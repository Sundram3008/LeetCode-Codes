class Solution {
    public int minOperations(int[] nums, int x) {
        int total=0;
        for(int i=0; i<nums.length; i++) total+= nums[i];
        int sumToRemove= total-x;
        int eleToRemove=0, currSum=0, l=0;
        if(sumToRemove == 0) return nums.length;
        for(int i=0; i<nums.length; i++){
            currSum+= nums[i];
            while(currSum> sumToRemove && l<i){
                currSum-= nums[l];
                l++;
            }
            if(currSum==sumToRemove){
                eleToRemove = Math.max(eleToRemove, i-l+1);
            }
        }
        if(eleToRemove==0) return -1;
        return nums.length- eleToRemove;
    }
}