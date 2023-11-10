class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjp) {
        vector<int> res;
        unordered_map<int, bool> vis;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<adjp.size(); i++){
            mp[adjp[i][0]].push_back(i);
            mp[adjp[i][1]].push_back(i);
        }
        int val=0;
        for(auto &i: mp){
            if(i.second.size()==1) val=i.first;
        }
        while(res.size()<adjp.size()+1){
            res.push_back(val);
            vis[val]=true;
            for(auto &i: mp[val]){
                if(!vis[adjp[i][0]]){
                    val= adjp[i][0];
                    break;
                }
                if(!vis[adjp[i][1]]){
                    val= adjp[i][1];
                    break;
                }
            }
        }
        return res;
    }
};