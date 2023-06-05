class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        if(co.size()<=2) return true;
        for(int i=2; i<co.size(); i++){
            int y1= co[i][1]-co[i-1][1], y0= co[i-1][1]-co[i-2][1];
            int x1= co[i][0]-co[i-1][0], x0= co[i-1][0]-co[i-2][0];
            if(y1*x0 != y0*x1) return false;
        }
        return true;
    }
};