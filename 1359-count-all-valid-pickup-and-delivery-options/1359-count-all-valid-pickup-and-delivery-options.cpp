class Solution {
public:
    long long int fact(int n){
        if(n==1) return 1;
        return (n*fact(n-1))%1000000007;
    }
    int countOrders(int n) {
        long long int ans =fact(n)%1000000007;
        
        for(int i=1; i<=n; i++)
            ans= (ans*(2*i -1))%1000000007;
        return ans;
    }
};