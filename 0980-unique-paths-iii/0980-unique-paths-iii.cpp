class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>> &grid, int r, int c, int x, int y, int empty){
        if(x<0 || y<0 || x==r || y==c || grid[x][y]==-1) return ;
        if(grid[x][y]==2){
            if(empty<=0) cnt++;
            return;
        }
        grid[x][y]=-1;
        dfs(grid, r, c, x-1, y, empty-1);
        dfs(grid, r, c, x, y-1, empty-1);
        dfs(grid, r, c, x+1, y, empty-1);
        dfs(grid, r, c, x, y+1, empty-1);
        grid[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(), x=0, y=0, empty=1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0) empty++;
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        grid[x][y]=0;
        dfs(grid, r, c, x, y, empty);
        return cnt;
    }
};