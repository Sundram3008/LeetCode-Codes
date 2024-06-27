class Solution {
    public int findCenter(int[][] edges) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n= edges.length;
        for(int i=0; i<n; i++){
            mp.put(edges[i][0], mp.getOrDefault(edges[i][0], 0)+1);
            mp.put(edges[i][1], mp.getOrDefault(edges[i][1], 0)+1);
        }
        for(Map.Entry<Integer, Integer> x: mp.entrySet()){
            if(x.getValue()== n) return x.getKey();
        }
        return -1;
    }
}