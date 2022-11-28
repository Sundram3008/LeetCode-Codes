class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost;
        unordered_set<int>  st;
        for(auto i: matches){
            lost[i[1]]++;
            st.insert(i[0]);
            st.insert(i[1]);
        }
        vector<vector<int>> ans(2);
        for(auto i: st){
            if(lost[i]==0) ans[0].push_back(i);
            else if(lost[i]==1) ans[1].push_back(i);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};