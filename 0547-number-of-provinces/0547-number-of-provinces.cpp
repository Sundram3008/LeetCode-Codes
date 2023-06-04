class Solution {
public:
    void dfs(vector<vector<int>> &graph, int &nodes, int &idx, vector<bool> &vis){
        if(vis[idx]) return ;
        vis[idx]=true;
        for(int i=0; i<nodes; i++){
            if(graph[idx][i]==1 && !vis[i]){
                dfs(graph, nodes, i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes= isConnected.size(), ans=0;
        vector<bool> vis(nodes, false);
        for(int i=0; i<nodes; i++){
            if(!vis[i]){
                dfs(isConnected, nodes, i, vis);
                ans++;
            }
        }
        return ans;
    }
};