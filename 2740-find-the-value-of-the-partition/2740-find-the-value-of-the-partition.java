class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);
        int ans=1000000000;
        for(int i=1; i<nums.length; i++){
            ans= Math.min(ans, nums[i]-nums[i-1]);
        }
        return ans;
    }
}