class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans=0;
        for(int i=0; i<nums.length/2; i++) 
            ans= Math.max(ans, nums[i]+ nums[nums.length-1-i]);
        return ans;
    }
}