class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<arr.length; i++){
            mp.put(arr[i], mp.getOrDefault(arr[i], 0)+1);
        }
        HashSet<Integer> st = new HashSet<>();
        for(Map.Entry<Integer, Integer> x: mp.entrySet()){
            if(st.contains(x.getValue())) return false;
            st.add(x.getValue());
        }
        return true;
    }
}