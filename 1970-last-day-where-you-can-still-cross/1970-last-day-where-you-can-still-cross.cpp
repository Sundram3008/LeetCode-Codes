class Solution {
public:
    vector<vector<int>> dir= {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool possible(int day, int r, int c, vector<vector<int>> &cells){
        vector<vector<int>> grid(r, vector<int> (c, 0));
        for(int i=0; i<day; i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
        queue<pair<int,int>> q;
        for(int i=0; i<c; i++){
            if(grid[0][i]==0)
                q.push({0,i});
            grid[0][i]=1;
        }
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x== r-1) return true;
            for(int i=0; i<4; i++){
                int nx= x+dir[i][0], ny= y+ dir[i][1];
                if(nx<0 || nx==r || ny<0 || ny==c || grid[nx][ny]==1) continue;
                q.push({nx, ny});
                grid[nx][ny]=1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int low=1, high= cells.size();
        while(low<=high){
            int mid= low+ ((high-low)/2);
            if(possible(mid, row, col, cells)){
                ans= mid;
                low= mid+1;
            }else high= mid-1;
        }
        return ans;
    }
};