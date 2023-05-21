class Solution {
public:
    
    int bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q, int n){
        int ans=0;
        vector<vector<int>> codnt= {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()){
            int xl=q.size();
            for(int i=0; i<xl; i++){
                int x=q.front().first, y=q.front().second;
                q.pop();
                //cout<<x<<" "<<y<<endl;
                for(int j=0; j<4; j++){
                    int nx=x+codnt[j][0], ny= y+codnt[j][1];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=1){
                        if(grid[nx][ny]==2) return ans;
                        else q.push({nx,ny});
                        grid[nx][ny]=1;
                        
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    void dfs(vector<vector<int>> &grid, int i, int j, int n){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return ;
        grid[i][j]=2;
        dfs(grid, i-1, j, n);
        dfs(grid, i, j-1, n);
        dfs(grid, i+1, j, n);
        dfs(grid, i, j+1, n);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        bool marked=false;
        for(int i=0; i<n && !marked; i++){
            for(int j=0; j<n && !marked; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j, n);
                    marked=true;
                }
            }
        }
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int x= bfs(grid, q,n);
        // for(auto i: grid){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return x;
    }
};