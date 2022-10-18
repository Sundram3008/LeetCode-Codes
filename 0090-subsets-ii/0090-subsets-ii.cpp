class Solution {
public:
    set<vector<int>> st;
    void helper(vector<int> v, int i, vector<int> temp){
        if(i>= v.size()){
            st.insert(temp);
            return;
        }
        temp.push_back(v[i]);
        helper(v, i+1, temp);
        temp.pop_back();
        helper(v, i+1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, temp);
        for(auto i: st) ans.push_back(i);
        return ans;
    }
};