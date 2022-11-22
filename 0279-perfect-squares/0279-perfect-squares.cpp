class Solution {
public:
    int numSquares(int n) {
        int cnt=0;
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1; i<=sqrt(n)+1; i++){
            for(int j=i*i; j<=n; j++){
                dp[j]= min(dp[j-(i*i)]+1, dp[j]);
            }
        }
        return dp[n];
    }
};