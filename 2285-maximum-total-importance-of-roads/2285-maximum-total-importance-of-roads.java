class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long []vals = new long[n];
        for(int i=0; i<roads.length; i++){
            vals[roads[i][0]]++;
            vals[roads[i][1]]++;
        }
        Arrays.sort(vals);
        long res=0;
        for(int i=0; i<n; i++) res+= (vals[i]*(i+1));
        return res;
    }
}