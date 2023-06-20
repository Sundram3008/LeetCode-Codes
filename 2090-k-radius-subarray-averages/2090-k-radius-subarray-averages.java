class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n =  nums.length, idx= k;
        int []ans = new int [n];
        for(int i=0; i<n; i++) ans[i]=-1;
        long sum = 0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(i>= (k*2)){
                ans[idx++]= (int)(sum/(k*2 +1));
                sum-= nums[i-k*2];
            }
        }
        return ans;
    }
}