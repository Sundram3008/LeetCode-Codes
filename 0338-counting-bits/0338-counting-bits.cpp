class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int l=1;
        for(int i=1; i<=n; i++){
            if(i && (!(i & (i - 1)))) l=i;
            ans[i]= ans[i%l]+1;
        }
        return ans;
    }
};