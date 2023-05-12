class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n= q.size();
        vector<long long> dp(n, 0);
        long long max_val=0;
        for(int i=n-1; i>=0; i--){
            long long curr_max= q[i][0];
            if(i+q[i][1]+1<n) curr_max+= dp[i+q[i][1]+1];
            max_val= max(curr_max, max_val);
            dp[i]= max_val;
        }
        return dp[0];
    }
};