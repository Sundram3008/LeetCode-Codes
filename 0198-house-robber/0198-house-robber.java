class Solution {
    public int rob(int[] nums) {
        int took=0, nottook=0;
        for(int i=0; i<nums.length; i++){
            int ntook= nottook+ nums[i];
            int nnottook = Math.max(took, nottook);
            nottook = nnottook;
            took = ntook;
        }
        return Math.max(took, nottook);
    }
}