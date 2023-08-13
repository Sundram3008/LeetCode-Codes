class Solution {
public:
    bool check(int idx, vector<int> &nums){
        return ((nums[idx]==nums[idx+1]&& nums[idx+1]==nums[idx+2] ) || nums[idx]+1== nums[idx+1] && nums[idx+1]+1 ==nums[idx+2]);
    }
    bool helper(int idx, int n, vector<int> &nums, vector<int> &dp){
        if(idx>=n) return true;
        if((n-idx)<2) return false;
        if(dp[idx]!= -1) return dp[idx];
        
        if(nums[idx]==nums[idx+1] && helper(idx+2, n, nums, dp)){
            dp[idx]=1;
            return true;
        }
        if(idx+2<n && check(idx, nums) && helper(idx+3, n, nums, dp)){
            dp[idx]=1;
            return true;
        }
        dp[idx]=0;
        return dp[idx];
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums.size(), nums, dp);
    }
};