class Solution {
    public int findNonMinOrMax(int[] nums) {
        int maxm=0, minm=Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++){
            if(maxm<nums[i]) maxm= nums[i];
            if(minm>nums[i]) minm= nums[i];
        }
        for(int i: nums) if(i!=minm && i!= maxm) return i;
        return -1;
    }
}