class Solution {
public:
    int mod=1e9+7;
    int helper(vector<vector<int>> &pre, int row, int col, int k, vector<vector<vector<int>>> &dp){
        if(pre[row][col]==0) return 0;
        if(dp[row][col][k]!= -1) return dp[row][col][k];
        if(k==0) return 1;
        int ways=0;
        for(int h=row+1; h< pre.size()-1; h++){
            if(pre[row][col] - pre[h][col] > 0){
                ways= (ways + helper(pre, h, col, k-1, dp))%mod;
            }
        }
        for(int v=col+1; v< pre[0].size()-1; v++){
            if(pre[row][col] - pre[row][v] > 0){
                ways= (ways + helper(pre, row, v, k-1, dp))%mod;
            }
        }
        ways%=mod;
        dp[row][col][k]=ways;
        return dp[row][col][k];
    }
    int ways(vector<string>& pizza, int k) {
        int r= pizza.size(), c= pizza[0].size();
        vector<vector<int>> preSum(r+1, vector<int> (c+1,0));
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                preSum[i][j] = preSum[i][j+1] + preSum[i+1][j] - preSum[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(k+1,-1)));
        return helper(preSum, 0, 0, k-1, dp);
    }
};