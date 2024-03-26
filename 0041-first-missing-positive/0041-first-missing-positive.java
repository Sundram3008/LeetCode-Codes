class Solution {
    public int firstMissingPositive(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for(int i=0; i<nums.length; i++){
            st.add(nums[i]);
        }
        int val=1;
        while(st.contains(val)) val++;
        return val;
    }
}