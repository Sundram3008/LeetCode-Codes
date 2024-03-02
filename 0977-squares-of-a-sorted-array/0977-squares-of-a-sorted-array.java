class Solution {
    public int[] sortedSquares(int[] nums) {
        int [] res = new int[nums.length];
        int l=0, r=nums.length-1, idx=nums.length-1;
        while(l<=r){
            if(Math.abs(nums[l])<Math.abs(nums[r])){
                res[idx]= nums[r];
                r--;
            }else{
                res[idx]= nums[l];
                l++;
            }
            //System.out.print(res[idx]+" ");
            idx--;
        }
        
        for(int i=0; i<nums.length; i++) res[i]*= res[i];
        return res;
    }
}