#define ll long long
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<ll> v;
        for(int i=1; i<=n; i++){
            if(pow(i, x)>n) break;
            v.push_back(pow(i,x));
        }
        int mod= 1e9+7;
        vector<vector<ll>> dp(v.size()+1, vector<ll>(n+1,0LL));
        dp[0][0]=1;
        for(int i=1; i<= v.size(); i++){
            dp[i][0]=1;
            for(ll j=1; j<= n; j++){
                if(j>= v[i-1]){
                    dp[i][j]+=dp[i-1][j - v[i-1]]+ dp[i-1][j]; 
                    dp[i][j]%=mod;
                }else dp[i][j]= dp[i-1][j];
            }
        }
        // for(auto i: dp){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[v.size()].back();
    }
};