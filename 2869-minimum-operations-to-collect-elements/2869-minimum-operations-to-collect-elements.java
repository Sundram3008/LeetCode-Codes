class Solution {
    public int minOperations(List<Integer> nums, int k) {
        long val = (long)Math.pow(2L,k)-1, got=0;
        for(int i=nums.size()-1; i>=0; i--){
            int x= nums.get(i);
            if(x<=k){
                got|=  (long)Math.pow(2, x-1);
            }
            if(val==got) return nums.size()-i;
        }
        return nums.size();
    }
}