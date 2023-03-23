class Solution {
public:
    void bfs(vector<vector<int>> &adj, int idx, vector<bool> &vis, int &extraLinks){
        queue<int> q;
        q.push(idx);
        while(!q.empty()){
            int temp= q.front();
            q.pop();
            for(int i=0; i<adj[temp].size(); i++){
                if(!vis[adj[temp][i]]){
                    vis[adj[temp][i]]=true;
                    q.push(adj[temp][i]);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()+1<n) return -1;
        vector<vector<int>> adj(n);
        for(auto i: connections){ 
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        int extraLinks=0, diffComp=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                diffComp++;
                bfs(adj, i, vis, extraLinks);
                vis[i]=true;

            }
        }
        return diffComp-1;
    }
};