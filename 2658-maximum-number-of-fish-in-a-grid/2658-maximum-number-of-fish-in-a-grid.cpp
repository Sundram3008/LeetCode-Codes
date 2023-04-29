class Solution {
public:
    
    // void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &val){
    //     if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || vis[i][j]==true || grid[i][j]==0) return ;
    //     vis[i][j]=true;
    //     val+=grid[i][j];
    //     dfs(i-1, j, grid, vis, val);
    //     dfs(i+1, j, grid, vis, val);
    //     dfs(i, j-1, grid, vis, val);
    //     dfs(i, j+1, grid, vis, val);
    // }
    // int findMaxFish(vector<vector<int>>& grid) {
    //     int ans=0, r= grid.size(), c= grid[0].size();
    //     for(int i=0; i<r; i++){
    //         for(int j=0; j<c; j++){
    //             if(grid[i][j]!=0){
    //                 int val=0;
    //                 vector<vector<bool>> vis(r, vector<bool> (c, false));
    //                 dfs(i, j, grid, vis, val);
    //                 ans= max(ans, val);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return 0;
        int res = grid[r][c];
        grid[r][c] = 0;
        for(auto d: dir) { 
            res += dfs(grid, r+d[0], c+d[1]);
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i< grid.size(); ++i){
            for(int j =0; j < grid[0].size(); ++j){
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};