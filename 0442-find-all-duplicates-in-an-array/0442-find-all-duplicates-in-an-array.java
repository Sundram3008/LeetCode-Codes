class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<nums.length; i++){
            int x= Math.abs(nums[i]);
            if(nums[x-1]<0){
                res.add(x);
            }else nums[x-1]*=-1;
        }
        return res;
    }
}