class Solution {
public:
    int help(vector<int>&days, vector<int> &costs, int idx, vector<int> &dp){
        if(idx>=days.size()) return 0;
        if(dp[idx]!= -1) return dp[idx];
        int ones= costs[0]+ help(days, costs, idx+1, dp);
        int i;
        for(i=idx; i<days.size(); i++){
            if(days[i]>= ( days[idx]+7)) break;
        }
        int week=costs[1] +help(days, costs, i, dp);
        int j;
        for(j=idx; j<days.size(); j++){
            if(days[j]>= (days[idx]+30)) break;
        }
        int month= costs[2]+ help(days, costs, j, dp);
        
        return dp[idx]= min({ones, week, month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(),-1);
        // return help(days,costs, 0, dp);
        vector<int> dp(days.size()+1, INT_MAX);
        int n=days.size();
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int ones= costs[0]+ dp[i+1];
            int j;
            for(j=i; j<days.size(); j++){
                if(days[j]>= ( days[i]+7)) break;
            }
            int week=costs[1] +dp[j];
            for(j=i; j<days.size(); j++){
                if(days[j]>= (days[i]+30)) break;
            }
            int month= costs[2]+ dp[j]; 
            dp[i]= min({ones, week, month});
        }
        return dp[0];
    }
};