class Solution {
public:
    int mod= 1000000007;
    long helper(int s, int a, int al, vector<vector<long>> &dp){
        if(s==0 && a==0) return 1;
        if(s==0 || a>=al || a<0) return 0;
        if(dp[s][a]!= -1) return dp[s][a];
        dp[s][a]= ((helper(s-1, a+1, al, dp))%mod + (helper(s-1, a-1, al, dp))%mod +(helper(s-1, a, al, dp))%mod)%mod;
        return dp[s][a];        
    }
    int numWays(int steps, int arrLen) {
        vector<vector<long>> dp(steps+1, vector<long>(steps+1, -1));
        return helper(steps, 0, arrLen, dp);
    }
};