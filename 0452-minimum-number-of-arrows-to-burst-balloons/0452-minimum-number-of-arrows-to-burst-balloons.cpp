class Solution {
public:
    static bool mycomp(vector<int> &a, vector<int> &b){
        if(a[1]!=b[1]) return a[1]<b[1];
        else return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), mycomp);
        int val=points[0][1], ans=1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]> val){
                ans++;
                val= points[i][1];
            }
        }
        return ans;
    }
};