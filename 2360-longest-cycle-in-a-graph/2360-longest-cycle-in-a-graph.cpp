class Solution {
public:
    
    void dfs(vector<int> &edges, int idx, vector<int> &dists, vector<bool> &vis, vector<bool> &isVis, int dist, int &ans){
        if(edges[idx]!=-1){
            if(!vis[idx]){
                vis[idx]=true;
                dists[idx]=dist;
                isVis[idx]=true;
                dfs(edges, edges[idx], dists, vis, isVis, dist+1, ans);
            }else if(isVis[idx]){
                ans= max(ans, dist- dists[idx]);
            }
            isVis[idx]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size(), ans=-1, dist=0;
        vector<int> dists(n, 0);
        vector<bool> visited(n, false), isVis(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i])
                dfs(edges, i, dists, visited, isVis, dist, ans);
        }
        return ans;
    }
};