class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>> q;
        q.push({src,0});
        map<pair<int,int>, int> mp;
        vector<vector<int>> adj(n);
        for(auto i: flights){
            adj[i[0]].push_back(i[1]);
            mp[{i[0],i[1]}]= i[2];
        }
        
        vector<int> ans(n, INT_MAX);
        ans[src]=0;
        for(int i=0; i<=k+1; i++){
            int size= q.size();
            for(int i=0; i<size; i++){
                int idx= q.front().first;
                int charge= q.front().second;
                q.pop();
                ans[idx]= min(ans[idx], charge);
                for(auto j: adj[idx]){
                    if(ans[j]> charge+mp[{idx,j}]){
                        q.push({j, charge+ mp[{idx,j}]});
                    }
                }
            }
            //cout<<endl;
        }
        return (ans[dst]==INT_MAX)? -1: ans[dst];
    }
};