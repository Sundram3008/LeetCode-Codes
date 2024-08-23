class Solution {
public:
#define ll long long
    ll helper(vector<int>& eda, vector<int>& edb, int idx, int aorb, vector<vector<ll>>& dp){
        if(idx>= eda.size()) return 0;
        if(dp[idx][aorb]!=LLONG_MIN) return dp[idx][aorb];
        ll val=0;
        if(aorb==1){
            val = max(val, eda[idx]+helper(eda, edb, idx+1, aorb, dp));
        }else{
            val = max(val, edb[idx]+helper(eda, edb, idx+1, aorb, dp));
        }
        val= max(val, helper(eda, edb, idx+1, 1-aorb, dp));
        dp[idx][aorb]=val;
        return val;
    }
    long long maxEnergyBoost(vector<int>& eda, vector<int>& edb) {
        vector<vector<ll>> dp(eda.size(),vector<ll>(2, LLONG_MIN)), dp1(eda.size(),vector<ll>(2, LLONG_MIN));
        ll a= helper(eda, edb, 0, 1, dp);
        ll b= helper(eda, edb, 0, 0, dp1);
        return max(a,b);
    }
};