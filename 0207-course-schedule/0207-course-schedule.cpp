class Solution {
public:
    bool haveCycle(int idx, vector<vector<int>> &g, vector<int> &vis){
        if(vis[idx]==1) return true;
        if(vis[idx]==0){
            vis[idx]=1;
            for(auto &i: g[idx]){
                if(haveCycle(i, g, vis)) return true;
            }
        }
        vis[idx]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<pre.size(); i++){
            graph[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=0; i<numCourses; i++){
            vector<int> vis(numCourses, 0);
            if(haveCycle(i, graph, vis)) return false;
        }
        return true;
    }
};