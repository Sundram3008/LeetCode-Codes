class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0,{0}});
        while(!q.empty()){
            int idx= q.front().first;
            vector<int> temp= q.front().second;
            q.pop();
            if(idx== graph.size()-1){
                ans.push_back(temp);
                continue;
            }
            for(auto i: graph[idx]){
                temp.push_back(i);
                q.push({i,temp});
                temp.pop_back();
            }
        }
        return ans;
    }
};