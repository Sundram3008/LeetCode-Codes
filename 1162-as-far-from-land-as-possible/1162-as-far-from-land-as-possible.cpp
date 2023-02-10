class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ans=-1;
        vector<vector<int>> val(grid.size(), vector<int> (grid[0].size(), 0));
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        for(int i=0;i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){ 
                    q.push({i,j});
                    val[i][j]=0;
                    vis[i][j]=true;
                }
            }
        }
        if(q.size()==0 || q.size()== grid.size()*grid.size()) return -1;
        vector<vector<int>> dir= {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty()){
            int x= q.front().first, y= q.front().second;
            q.pop();
            for(auto i: dir){
                int xn= x+i[0], yn= y+i[1];
                if(xn<0 || yn<0 || xn>= grid.size() || yn>= grid[0].size() || vis[xn][yn]==true) continue;
                    q.push({xn,yn});
                    val[xn][yn]= val[x][y]+1;
                    vis[xn][yn]=true;
                
            }
        }
        for(auto i: val){
            for(auto j: i){
                ans= max(ans, j);
            }
        }
        return ans;
    }
};