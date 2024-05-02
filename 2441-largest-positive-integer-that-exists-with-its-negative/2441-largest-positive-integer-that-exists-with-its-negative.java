class Solution {
    public int findMaxK(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for(int i: nums) 
            if(i<0) st.add(-1*i);
        
        int res=-1;
        for(int i: nums){
            if(i>0){
                if(st.contains(i)) res = Math.max(res, i);
            }
        }
        return res;
    }
}