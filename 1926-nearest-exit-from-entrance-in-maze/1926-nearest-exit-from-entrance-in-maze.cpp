class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0], e[1]});
        vector<pair<int,int>> vp= {{-1,0},{0,-1},{1,0}, {0,1}};
        int lvl=0, r= maze.size(), c= maze[0].size();
        maze[e[0]][e[1]]='+';
        while(!q.empty()){
            int n= q.size();
            lvl++;
            for(int i=0; i<n; i++){
                auto temp= q.front();
                q.pop();
                for(auto j: vp){
                    int nx= temp.first+ j.first, ny= temp.second+ j.second;
                    if(nx<0 || nx>=r || ny<0 || ny>=c || maze[nx][ny]=='+') continue;
                    if(nx==0 || ny==0 || nx==r-1 || ny== c-1) return lvl;
                    maze[nx][ny]='+';
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};