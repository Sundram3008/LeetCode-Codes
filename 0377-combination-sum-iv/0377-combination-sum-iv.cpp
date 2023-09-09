class Solution {
public:
    int combs(vector<int> &v, int k, vector<vector<int>> &dp){
        if(k==0) return 1;
        int ans=0;
        for(int i=0; i<v.size(); i++){
            if(dp[i][k]!= -1){
                ans+= dp[i][k];
                continue;
            }
            if(v[i]<= k){ 
                dp[i][k]=combs(v, k-v[i], dp);
                ans+= dp[i][k];
            }
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        return combs(nums, target, dp);
    }
};