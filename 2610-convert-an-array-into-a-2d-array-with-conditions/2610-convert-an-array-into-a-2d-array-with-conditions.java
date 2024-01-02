class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        int idx=-1, num=nums[0];
        for(int i=0; i<nums.length; i++){
            if(nums[i]== num){
                if(res.size()==idx+1){
                    res.add(new ArrayList<>());
                }
                idx++;
            }else{
                num=nums[i];
                idx=0;
            }
            res.get(idx).add(nums[i]);
        }
        return res;
    }
}