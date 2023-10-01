class Solution {
    public long maximumTripletValue(int[] nums) {
        int mfb[] = new int[nums.length];
        int maxi= Integer.MIN_VALUE;
        for(int i=nums.length-1; i>=0; i--){
            maxi= Math.max(nums[i], maxi);
            mfb[i]= maxi;
        }
        long ans=0;
        maxi = nums[0];
        for(int i=1; i<nums.length-1; i++){
            ans= Math.max(ans, 1L*(maxi-nums[i])*mfb[i+1]);
            maxi= Math.max(maxi, nums[i]);
        }
        return ans;
    }
}