class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        int row= obstacleGrid.length, col= obstacleGrid[0].length;
        
        if(obstacleGrid[0][0]==1 || obstacleGrid[row-1][col-1]==1) return 0;
        obstacleGrid[0][0]=1;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if((i==0 && j==0) || obstacleGrid[i][j]!= 1) obstacleGrid[i][j]+= ((i-1>=0)?obstacleGrid[i-1][j]: 0) + ((j-1>=0)?obstacleGrid[i][j-1]:0);
                else obstacleGrid[i][j]=0;
            }
        }
        return obstacleGrid[row-1][col-1];
    }
}