class Solution {
    public int helper(int i, int j, int r, int c, int mm, int[][][] dp){
        if(i<0 || j<0 || i==r || j==c) return 1;
        if(mm==0) return 0;
        if(dp[i][j][mm]!= -1) return dp[i][j][mm];
        long total =0;
        total+= helper(i-1, j, r, c, mm-1, dp);
        total+= helper(i, j-1, r, c, mm-1, dp);
        total+= helper(i+1, j, r, c, mm-1, dp);
        total+= helper(i, j+1, r, c, mm-1, dp);
        dp[i][j][mm]= (int)(total%1000000007);
        return dp[i][j][mm];
    }
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int [][][]dp = new int[m+1][n+1][maxMove+1];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=maxMove; k++){
                    dp[i][j][k]= -1;
                }
            }
        }
        return helper(startRow, startColumn, m, n, maxMove, dp);
    }
}