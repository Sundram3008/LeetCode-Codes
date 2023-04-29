class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &val){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || vis[i][j]==true || grid[i][j]==0) return ;
        vis[i][j]=true;
        val+=grid[i][j];
        dfs(i-1, j, grid, vis, val);
        dfs(i+1, j, grid, vis, val);
        dfs(i, j-1, grid, vis, val);
        dfs(i, j+1, grid, vis, val);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0, r= grid.size(), c= grid[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]!=0){
                    int val=0;
                    vector<vector<bool>> vis(r, vector<bool> (c, false));
                    dfs(i, j, grid, vis, val);
                    ans= max(ans, val);
                }
            }
        }
        return ans;
    }
};