class Solution {
public:
    int numTilings(int n) {
        vector<int> v(max(4,n+1),0);
        v[1]=1,v[2]=2, v[3]=5;
        int mod= 1e9+7;
        for(int i=4; i<=n; i++){
            v[i]= ((2*v[i-1])%mod+ v[i-3])%mod;
        }
        return v[n];
    }
};