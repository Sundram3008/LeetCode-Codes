class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Map<Integer, Integer> mp= new HashMap<>();
        for(int i: target){
            mp.put(i, mp.getOrDefault(i, 0)+1);
        }
        for(int i: arr){
            if(mp.containsKey(i)==false || mp.get(i)<=0) return false;
            mp.put(i, mp.get(i)-1);
        }
        return true;
    }
}