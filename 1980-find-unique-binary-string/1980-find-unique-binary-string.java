class Solution {
    public String findDifferentBinaryString(String[] nums) {
        String res= "";
        for(int i=0; i<nums.length; i++) res+= (nums[i].charAt(i)=='1')? "0":"1";
        return res;
    }
}