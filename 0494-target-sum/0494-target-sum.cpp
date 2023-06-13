class Solution {
public:
    int solve(int idx, int t, vector<int> &v, vector<map<int,int>> &dp){
        if(idx<0){
            if(t==0){
                return 1;
            }
            else return 0;
        }
        if(dp[idx].find(t)!=dp[idx].end()) return dp[idx][t];
            int plus= solve(idx-1, t+v[idx], v, dp);
            int minus= solve(idx-1, t-v[idx], v, dp);
            dp[idx][t]= plus+minus;
            return dp[idx][t];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<map<int,int>> dp(nums.size()+1);
        return solve(nums.size()-1, target, nums, dp);
    }
};