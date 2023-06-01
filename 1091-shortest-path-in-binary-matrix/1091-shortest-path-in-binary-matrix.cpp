class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<vector<int>> q;
        q.push({0,0,1});
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                int x= q.front()[0], y= q.front()[1], nodes= q.front()[2];
                q.pop();
                if(x==n-1 && y==n-1) return nodes;
                for(int j=0; j<dir.size(); j++){
                    int nx= x+dir[j][0], ny= y+dir[j][1], nnode= nodes+1;
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx, ny, nnode});
                    }
                }
            }
        }
        return -1;
    }
};