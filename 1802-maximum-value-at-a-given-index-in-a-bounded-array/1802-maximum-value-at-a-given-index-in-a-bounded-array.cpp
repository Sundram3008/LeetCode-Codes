class Solution {
public:
#define ll long long int
    bool solExists(int ls, int rs, int mid, int sum){
        ll il= mid-1, ir= mid-1;
        ll fl= (mid-ls >=0)? mid-ls: 0, fr= (mid-rs >=0)? mid-rs:0;
        ll ltot= (il*(il+1)/2) - (fl*(fl-1)/2);
        ll rtot= (ir*(ir+1)/2) - (fr*(fr-1)/2);
        ll total= mid;
        if(ls>0) total+= ltot;
        if(rs>0) total+=rtot;
        return (total<=sum);
    }
    int maxValue(int n, int index, int maxSum) {
        if(n==1) return maxSum;
        maxSum-=n;
        int low=0, high=maxSum, eleInL= index, eleInR= n-index-1, ans=1;
        while(low<=high){
            int mid= (low+high+1)/2;
            if(solExists(eleInL, eleInR, mid, maxSum)){
                ans= mid+1;
                low= mid+1;
            }else{
                high= mid-1;
            }
        }
        return ans;
    }
};