class Solution {
    public int[][] construct2DArray(int[] og, int m, int n) {
        if(og.length!= m*n) return new int[][]{};
        int [][] res= new int[m][n];
        int r=0, c=0;
        for(int i: og){
            if(c==n){
                r++;
                c=0;
            }
            res[r][c++]= i;
        }
        return res;
    }
}