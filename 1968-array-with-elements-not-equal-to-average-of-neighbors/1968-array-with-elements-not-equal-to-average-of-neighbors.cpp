class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(l!=r){
                ans.push_back(nums[l]);
                ans.push_back(nums[r]);
            }else ans.push_back(nums[l]);
            l++,r--;
        }
        return ans;
    }
};