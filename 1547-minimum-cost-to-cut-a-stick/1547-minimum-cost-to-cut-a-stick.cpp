class Solution {
public:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int idx= i; idx<=j; idx++){
            mini = min(mini, cuts[j+1]-cuts[i-1] + helper(i, idx-1, cuts, dp) + helper(idx+1,j, cuts, dp));
        }
        dp[i][j]=mini;
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        // return helper(1, cuts.size() -2, cuts, dp);
        int c= cuts.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1, 0));
        for(int i=c-2; i>=1; i--){
            for(int j=1; j<=c-2; j++){
                for(int idx= i; idx<=j; idx++){
                    dp[i][j] = min((dp[i][j]==0)? INT_MAX:dp[i][j], cuts[j+1]-cuts[i-1] + dp[i][idx-1] + dp[idx+1][j]);
                }
            }
        }
        return dp[1][c-2];
    }
};