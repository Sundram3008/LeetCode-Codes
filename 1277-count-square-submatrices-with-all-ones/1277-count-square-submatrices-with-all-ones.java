class Solution {
    public int countSquares(int[][] mat) {
        int ans=0;
        for(int i=0; i<mat.length; i++) ans+= mat[i][0];
        for(int i=1; i<mat[0].length; i++) ans+= mat[0][i];
        for(int i=1; i<mat.length; i++){
            for(int j=1; j<mat[0].length; j++){
                if(mat[i][j]==1){
                    mat[i][j]+= Math.min(mat[i][j-1], Math.min(mat[i-1][j], mat[i-1][j-1]));
                }
                ans+= mat[i][j];
            }
        }
        return ans;
    }
}