class Solution {
    public int maximumLength(int[] nums) {
        int alle=0, allo=0, eo=0, oe=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]%2==0){
                alle++;
                if(eo%2==0) eo++;
                if(oe%2==1) oe++;
            }else{
                allo++;
                if(oe%2==0) oe++;
                if(eo%2==1) eo++;
            }
        }
        return Math.max(alle, Math.max(allo, Math.max(eo, oe)));
    }
}