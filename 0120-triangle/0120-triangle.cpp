class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &t, vector<vector<int>> &dp){
        if(i== t.size()-1) return t[i][j];
        if(dp[i][j]!= -1) return dp[i][j];
        int d= t[i][j]+helper(i+1, j, t, dp);
        int dr= t[i][j]+helper(i+1, j+1, t, dp);
        dp[i][j]= min(d, dr);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>> dp(t.size(), vector<int>(t.size(), -1));
        return helper(0, 0, t, dp);
    }
};