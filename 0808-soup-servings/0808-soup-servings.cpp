class Solution {
public:
    double helper(int x, int y, map<pair<int, int>, double> &dp){
        if(x>0 && y<=0) return 0.0;
        if(x<=0 && y<=0) return 0.5;
        if(x<=0 && y>0) return 1.0;
        if(dp.find({x,y})!=dp.end()){
            return dp[{x,y}];
        }
        double a= helper(x-100, y, dp);
        double b= helper(x-75, y-25, dp);
        double c= helper(x-50, y-50, dp);
        double d= helper(x-25, y-75, dp);
        double prob = 0.25 *(a +b+c+d);
        dp[{x,y}]= prob;
        return prob;
    }
    double soupServings(int n) {
        if(n>=5000) return 1.0;
        map<pair<int,int>, double> dp;
        return helper(n, n, dp);
    }
};