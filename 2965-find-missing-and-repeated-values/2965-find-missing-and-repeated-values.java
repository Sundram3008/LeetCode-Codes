class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        Set<Integer> st = new HashSet<>();
        int [] ans = new int[2];
        int val=0, N= grid.length;
        N*=N;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[i].length; j++){
                if(st.contains(grid[i][j])) ans[0]= grid[i][j];
                st.add(grid[i][j]);
                val+= grid[i][j];
            }
        }
        ans[1]= ((N*(N+1))/2)- (val- ans[0]);
        return ans;
    }
}