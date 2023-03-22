class Solution {
public:
    void dfs(vector<vector<int>> &roads, map<pair<int,int>, int> &mp, int idx, int &ans, vector<bool> &vis){
        for(int i=0; i<roads[idx].size(); i++){
            if(!vis[roads[idx][i]]){
                vis[roads[idx][i]]=true;
                dfs(roads, mp, roads[idx][i], ans, vis);
            }
            ans= min(ans, mp[{idx, roads[idx][i]}]);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n+1);
        map<pair<int,int>,int> dist;
        vector<bool> vis(n+1, false);
        int ans=INT_MAX;
        for(auto &i: roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            dist[{i[0],i[1]}]= i[2];
            dist[{i[1],i[0]}]= i[2];
        }
        dfs(adj, dist, 1, ans, vis);
        return ans;
    }
};