class Solution {
public:
    
    
    int dsu(int x, vector<int> &parents){
        if(parents[x] ==x){
            return x;
        }else{
            return parents[x]= dsu(parents[x], parents);
        }
    }
    static bool mycomp(vector<int> &a, vector<int> b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);
        vector<bool> ans(q.size(), false);
        sort(e.begin(), e.end(), mycomp);
        vector<pair<int, int>> p;
        for(int i=0; i<q.size(); i++){
            p.push_back({q[i][2],i});
        }
        sort(p.begin(), p.end());
        
        int j=0;
        for(int i=0; i<q.size(); i++){
            while(j<e.size() && e[j][2] < p[i].first){
                int u= e[j][0], v=e[j][1];
                int pu = dsu(u,parents), pv= dsu(v, parents);
                if(pu!=pv){
                    parents[pu]= pv;
                }
                j++;
            }
            int u= q[p[i].second][0], v= q[p[i].second][1];
            int pu = dsu(u,parents), pv= dsu(v, parents);
            if(pu==pv){
                ans[p[i].second]=true;
            }
        }
        return ans;
    }
};