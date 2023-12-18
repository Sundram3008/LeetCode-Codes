class Solution {
    public int maxProductDifference(int[] nums) {
        int maxi=0, smaxi=0, mini=Integer.MAX_VALUE, smini= Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++){
            if(maxi< nums[i]){
                smaxi= maxi;
                maxi= nums[i];
            }else if(smaxi< nums[i]) smaxi= nums[i];
            if(mini > nums[i]){
                smini= mini;
                mini = nums[i];
            }else if(smini> nums[i]) smini = nums[i];
        }
        
        return ((maxi*smaxi) - (mini *smini));
    }
}