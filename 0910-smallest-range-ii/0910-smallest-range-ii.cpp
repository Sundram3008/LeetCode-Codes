class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=nums.back()-nums[0];
        for(int i=0; i<nums.size()-1; i++){
            int mini = min(nums[0]+k, nums[i+1]-k);
            int maxi = max(nums[i]+k, nums[nums.size()-1]-k);
            ans= min(ans,maxi-mini);
        }
        return ans;
    }
};