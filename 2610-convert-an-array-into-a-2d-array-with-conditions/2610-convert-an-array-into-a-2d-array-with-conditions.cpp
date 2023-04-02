class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=0;
        for(auto i: nums) mp[i]++, n= max(n, mp[i]);
        vector<vector<int>> ans(n);
        for(auto i: mp){
            for(int j=0; j<i.second; j++){
                ans[j].push_back(i.first);
            }
        }
        return ans;
    }
};