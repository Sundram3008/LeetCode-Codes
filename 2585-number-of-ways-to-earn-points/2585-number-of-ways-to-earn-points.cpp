class Solution {
public:
    int mod= 1000000007;
    int helper(int t, vector<vector<int>> &types, int idx, vector<vector<int>> &dp){
        if(t==0) return 1;
        if(idx==types.size() || t<0) return 0;
        if(dp[idx][t]!= -1) return dp[idx][t];
        int ways=0;
        for(int i=0; i<=types[idx][0]; i++){
            if(t- (types[idx][1]*i)>=0)
                ways= (ways+helper(t-(types[idx][1]*i), types, idx+1, dp))%mod;
            else break;
        }
        dp[idx][t]=ways;
        return ways;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(types.size(), vector<int>(target+1, -1));
        return helper(target, types, 0, dp);
    }
};