class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int r= grid.length, c= grid[0].length;
        int []rows= new int[r], cols= new int[c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                rows[i]+= grid[i][j];
                cols[j]+= grid[i][j];
            }
        }
        int [][] res = new int[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                res[i][j]= rows[i]+ cols[j] - (r- rows[i]) - (c-cols[j]);
            }
        }
        return res;
    }
}