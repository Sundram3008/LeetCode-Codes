class Solution {
    
    public static boolean dfs(int[][] grid, int i, int j, int r, int c, boolean[][] vis){
        if(i<0 || j<0 || i>=r || j>=c) return false;
        if(grid[i][j]==1 || vis[i][j]==true) return true;
        vis[i][j]=true;
        boolean x=true;
        x&= dfs(grid, i+1, j, r, c, vis);
        x&= dfs(grid, i, j+1, r, c, vis);
        x&= dfs(grid, i-1, j, r, c, vis);
        x&= dfs(grid, i, j-1, r, c, vis);
        return x;
    }
    public int closedIsland(int[][] grid) {
        int r = grid.length, c = grid[0].length, ans=0; 
        boolean [][] vis = new boolean[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0 && vis[i][j]==false){
                    if(dfs(grid, i, j, r, c, vis)) ans++;
                }
            }
        }
        return ans;
    }
}