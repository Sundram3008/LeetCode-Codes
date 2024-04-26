class Solution {
    public int minFallingPathSum(int[][] grid) {
        int r= grid.length, c= grid[0].length;
        int mini=0, miniIdx=0, secondMini=0, secondMiniIdx=1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(miniIdx==j)
                    grid[i][j]+= secondMini;
                else
                    grid[i][j]+= mini;
            }
            mini = secondMini= Integer.MAX_VALUE;
            miniIdx =  secondMiniIdx = 1;
            for(int j=0; j<c; j++){
                if(grid[i][j]<mini){
                    secondMini= mini;
                    secondMiniIdx= miniIdx;
                    mini=grid[i][j];
                    miniIdx= j;
                }else if(grid[i][j]<secondMini){
                    secondMini= grid[i][j];
                    secondMiniIdx= j;
                }
            }
        }
        return mini;
    }
}