class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m= mat.size(), n= mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        int steps=1;
        int dirx[]= {-1, 0, 1, 0};
        int diry[]= {0, -1, 0, 1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    vis[i][j]=true;
                }
            }
        }
        
        while(!q.empty()){
            int r=q.size();
            for(int i=0; i<r; i++){
                int x= q.front().first, y= q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx= x+dirx[j], ny= y+diry[j];
                    if(nx<0 || ny<0 || nx==m || ny==n || mat[nx][ny]!=1 || vis[nx][ny]) continue;
                    
                    mat[nx][ny]= steps;
                    vis[nx][ny]= true;
                    q.push({nx, ny});
                }
            }
            steps++;
        }
        return mat;
    }
};