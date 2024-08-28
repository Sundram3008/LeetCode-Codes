class Solution {
public:
    // int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    //     int res=0, r=grid1.size(), c= grid1[0].size();
    //     vector<vector<int>> dir= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    //     for(int i=0; i<r; i++){
    //         for(int j=0; j<c; j++){
    //             bool allAval=true;
    //             if(grid2[i][j]==1){
    //                 queue<pair<int, int>> q;
    //                 q.push({i, j});
    //                 while(!q.empty()){
    //                     int x= q.front().first;
    //                     int y= q.front().second;
    //                     q.pop();
    //                     if(grid1[x][y]== 0) allAval=false;
    //                     for(auto &k: dir){
    //                         int nx= x+k[0], ny= y+k[1];
    //                         if(nx<r && nx>=0 && ny<c && ny>=0 && grid2[nx][ny]==1){
    //                             grid2[nx][ny]=0;
    //                             q.push({nx, ny});
    //                         }
    //                     }
    //                 }
    //                 if(allAval) res++;
    //             }
    //         }
    //     }
    //     return res;
    // }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int &res) {
        int m = grid1.size(), n = grid1[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return;
        if(grid1[x][y] == 0 && grid2[x][y] == 1) {
            res = false;
        }
        if(grid2[x][y] == 0) return;
        grid2[x][y] = 0;
        dfs(grid1, grid2, x + 1, y, res);
        dfs(grid1, grid2, x, y + 1, res);
        dfs(grid1, grid2, x - 1, y, res);
        dfs(grid1, grid2, x, y - 1, res);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    int res = true;
                    dfs(grid1, grid2, i, j, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};