class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int i, int j, int r, int c, vector<vector<bool>> & vis, int &cnt){
        if(i<0 || j<0 || i>=r || j>=c) return false;
        if(grid[i][j]==0 || vis[i][j]==true) return true;
        vis[i][j]=true;
        bool x=true;
        cnt++;
        x&= dfs(grid, i+1, j, r, c, vis, cnt);
        x&= dfs(grid, i, j+1, r, c, vis, cnt);
        x&= dfs(grid, i-1, j, r, c, vis, cnt);
        x&= dfs(grid, i, j-1, r, c, vis, cnt);
        return x;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans=0; 
        vector<vector<bool>> vis (r, vector<bool>(c, false));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int cnt=0;
                    if(dfs(grid, i, j, r, c, vis, cnt)) ans+= cnt;
                }
            }
        }
        return ans;
    }
};