class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(target<n||(target/k)>=n&&(target%k)!=0){
            return 0;
        }
        int MOD = 1000000007;
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int m=1;m<=k&&m<=j;m++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-m])%MOD;
                }
            }
        }
        return dp[n][target];
    }
};