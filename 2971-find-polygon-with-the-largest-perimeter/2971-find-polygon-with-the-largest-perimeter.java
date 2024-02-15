class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long sum=0;
        int i=0;
        for(i=0; i<nums.length; i++) sum= nums[i]+sum;
        for(i=nums.length-1; i>=0; i--){
            if(nums[i]<sum-nums[i]) break;
            sum-= nums[i];
        }
        return (i>=2)?sum:-1;
    }
}