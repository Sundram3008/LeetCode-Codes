class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        cost.push_back(0);
        vector<int> dp(n+2, 0);
        dp[0]=0;
        dp[1]= cost[0];
        for(int i=2; i<=n+1; i++){
            dp[i]= min(dp[i-1], dp[i-2])+ cost[i-1];
        }
        return dp.back();
    }
};