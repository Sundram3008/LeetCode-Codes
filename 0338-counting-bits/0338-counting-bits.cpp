class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int l=1, b=1;
        for(int i=1; i<=n; i++){
            if(i && (!(i & (i - 1)))){
                ans[i]=1;
                b=i;
                l=1;
            }else ans[i]+= ans[b]+ans[l++];
        }
        return ans;
    }
};