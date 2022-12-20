class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        unordered_map<int,bool> mp;
        queue<pair<int, vector<int>>> q;
        q.push({0,{0}});
        vector<vector<int>> ans;
        while(!q.empty()){
            int x= q.front().first;
            vector<int> v= q.front().second;
            q.pop();
            for(int i=0; i<graph[x].size(); i++){
                v.push_back(graph[x][i]);
                q.push({graph[x][i], v});
                v.pop_back();
            }
            if(v.back()==n-1) ans.push_back(v);
        }
        return ans;
    }
};