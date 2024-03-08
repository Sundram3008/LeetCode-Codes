class Solution {
    public int maxFrequencyElements(int[] nums) {
//         HashMap<Integer, Integer> mp = new HashMap<>();
//         int maxFreq=0, result=0;
        
//         for(int i=0; i<nums.length; i++){ 
//             mp.put(nums[i], mp.getOrDefault(nums[i], 0)+1);
//             maxFreq= Math.max(maxFreq, mp.get(nums[i]));
//         }
        
//         for(Map.Entry<Integer, Integer> itr : mp.entrySet()){
//             if(itr.getValue()==maxFreq) result+= maxFreq;
//         }
//         return result;
        int [] freqs = new int[101];
        int maxFreq=0;
        for(int i=0; i<nums.length; i++){
            freqs[nums[i]]++;
            maxFreq= Math.max(maxFreq, freqs[nums[i]]);
        }
        int result=0;
        for(int i=1; i<=100; i++) {
            if(maxFreq== freqs[i]) result+= maxFreq;
        }
        return result;
    }
}