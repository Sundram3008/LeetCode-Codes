class Solution {
    public int minOperations(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<> ();
        for(int i=0; i<nums.length; i++){
            int x= mp.getOrDefault(nums[i], 0);
            mp.put(nums[i], x+1);
        }
        int ans=0;
        for(Map.Entry m: mp.entrySet()){
            int val = (Integer)m.getValue();
            if(val==1) return -1;
            ans+= (val/3) + ((val%3>0)?1:0);
        }
        return ans;
    }
}