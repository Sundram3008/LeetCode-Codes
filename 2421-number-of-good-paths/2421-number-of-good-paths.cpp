class DSU{
    public :
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
    }
    int find(int idx){
        if(parent[idx]==idx) return idx;
        parent[idx]= find(parent[idx]);
        return parent[idx];
    }
    void combine(int x, int y){
        int xParent= find(x), yParent= find(y);
        if(xParent==yParent) return;
        parent[yParent]= xParent;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
        return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
    }); // sorting edges on the basis of less values such that while iterating for ans it will be sure only nodes with less value are present in graphs
        int n= vals.size(),ans=n;
        DSU dsu(n);
        vector<unordered_map<int, int>> mp(n);
        for(int i=0; i<n; i++){
            mp[i][vals[i]]=1;
        }
        int maxi, u, v, up, vp;
        for(vector<int> &i : edges){
            u = i[0], v= i[1];
            maxi= max(vals[u], vals[v]); // bcz we know starting should be maximum
            up= dsu.find(u); // finding the parent i.e. from which parent or graph this first node belongs
            vp= dsu.find(v); // finding the parent i.e. from which parent or graph this second node belongs
            dsu.combine(up, vp); // combining both the trees in which u and v belongs
            ans+= mp[up][maxi] * mp[vp][maxi]; // now as maxi is storing the val of the starting node and mp [u || v][maxi] will tell us in the graph of u is our max valuw available and same it will tell for v hence it becomes clear that 1st condition is satisfied and 2nd codition is satisfied because maxi if existing in both graph hence we get the number of paths by multiplying them
            mp[up][maxi]+=  mp[vp][maxi]; // merge the frequency of v in u of maxi as we have combined them into single graph
            mp[vp].erase(maxi); // erase because merged in u graph;
        }
        return ans;
    }
};