class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_map<int, bool> mp;
        q.push(0);
        mp[0]=true;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            mp[x]=true;
            for(int i=0; i<rooms[x].size(); i++){
                if(!mp[rooms[x][i]])
                    q.push(rooms[x][i]);
            }
            if(mp.size()==rooms.size()) return true;
        }
        return false;
    }
};