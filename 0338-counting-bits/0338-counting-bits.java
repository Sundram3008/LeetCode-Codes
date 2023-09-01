class Solution {
    public int[] countBits(int n) {
        int []ans= new int[n+1];
        int l=1;
        for(int i=1; i<=n; i++){
            if(i != 0 && (i & (i - 1)) == 0) l=i; // condition to check if a number is power of 2 ans update the nearest smaller power of 2
            ans[i]= ans[i%l]+1;
        }
        return ans;
    }
}