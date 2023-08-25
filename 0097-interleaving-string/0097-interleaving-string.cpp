class Solution {
public:
    bool helper(int i1, int i2, int i3, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp){
        
        if(i3==s3.size()) return (i1==s1.length() && i2==s2.length());
        if(dp[i1][i2][i3]!= -1) return dp[i1][i2][i3];
        bool f=false;
        if(i1< s1.length() && s1[i1]==s3[i3] && helper(i1+1, i2, i3+1, s1, s2, s3, dp)) f= true;
        if(i2<s2.length() && s2[i2]==s3[i3] && helper(i1, i2+1, i3+1, s1, s2, s3, dp)) f= true;
        dp[i1][i2][i3]= f;
        return f;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};