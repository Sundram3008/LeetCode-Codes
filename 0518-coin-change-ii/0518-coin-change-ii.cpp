class Solution {
public:
    int helper(int amount, vector<int> &coins, int i, vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || i>=coins.size()) return 0;
        if(dp[i][amount]!= -1) return dp[i][amount];
        int ways=0;
        ways+= helper(amount-coins[i],coins, i, dp);
        ways+= helper(amount, coins, i+1, dp);
        dp[i][amount]=ways;
        return ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return helper(amount, coins, 0, dp);
    }
};