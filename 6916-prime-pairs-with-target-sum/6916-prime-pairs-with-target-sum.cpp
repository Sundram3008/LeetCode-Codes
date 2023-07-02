class Solution {
public:
    void sieveOfEra(int n, vector<bool> &primes){
        primes[0]=false;
        primes[1]=false;
        for(int i=2; i<=n; i++){
            int x= i+i;
            while(x<=n){
                primes[x]=false;
                x+=i;
            }
        }
        return ;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n+1, true);
        vector<vector<int>> ans;
        sieveOfEra(n, primes);
        for(int i=0; i<= (n/2); i++){
            if(primes[i] && primes[n-i]) ans.push_back({i, n-i});
        }
        return ans;
    }
};