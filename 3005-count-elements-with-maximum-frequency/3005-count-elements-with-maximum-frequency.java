class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int maxFreq=0, result=0;
        
        for(int i=0; i<nums.length; i++){ 
            mp.put(nums[i], mp.getOrDefault(nums[i], 0)+1);
            maxFreq= Math.max(maxFreq, mp.get(nums[i]));
        }
        
        for(Map.Entry<Integer, Integer> itr : mp.entrySet()){
            if(itr.getValue()==maxFreq) result+= maxFreq;
        }
        return result;
    }
}