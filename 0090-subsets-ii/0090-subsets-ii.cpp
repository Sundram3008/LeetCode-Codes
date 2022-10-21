class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> v, int i, vector<int> temp){
        if(i>= v.size()) return;
        for(int j=i; j<v.size(); j++){
            if(j==i){
                temp.push_back(v[j]);
                ans.push_back(temp);
                helper(v, j+1, temp);
                temp.pop_back();
            }
            else{
                if(v[j]!=v[j-1]){
                    temp.push_back(v[j]);
                    ans.push_back(temp);
                    helper(v,j+1, temp);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        ans.push_back({});
        helper(nums, 0, temp);
        return ans;
    }
};