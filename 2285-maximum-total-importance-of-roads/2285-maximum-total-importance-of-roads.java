class Solution {
    public long maximumImportance(int n, int[][] roads) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        for(int i=0; i<roads.length; i++){
            mp.put(roads[i][0], mp.getOrDefault(roads[i][0], 0)+1);
            mp.put(roads[i][1], mp.getOrDefault(roads[i][1], 0)+1);
        }
        
        long []vals = new long[n];
        for(Map.Entry<Integer, Integer> x: mp.entrySet()){
            vals[x.getKey()]= x.getValue();
        }
        Arrays.sort(vals);
        long res=0;
        for(int i=0; i<n; i++) res+= (vals[i]*(i+1));
        return res;
    }
}