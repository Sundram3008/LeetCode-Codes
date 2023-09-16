class Solution {
public:
#define pp pair<int, pair<int, int>>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r= heights.size(), c=heights[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> vals(r, vector<int>(c, INT_MAX));
        vals[0][0]=0;
        pq.push({0,{0,0}});
        vector<vector<int>> dir= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.empty()){
            auto temp= pq.top();
            pq.pop();
            int x= temp.second.first;
            int y= temp.second.second;
            int val= temp.first;
            if(x==r-1 && y==c-1) return val;
            for(int j=0; j<4; j++){
                int nx= x+dir[j][0], ny= y+ dir[j][1];
                if(nx<0 || ny<0 || nx == r || ny==c) continue;
                int diff= max(abs(heights[nx][ny]- heights[x][y]), val);
                if(diff< vals[nx][ny]){
                    vals[nx][ny]= diff;
                    pq.push({diff, {nx, ny}});
                }
            }
        }
        return vals[r-1][c-1];
    }
};