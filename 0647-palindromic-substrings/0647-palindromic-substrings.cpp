class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool> (s.size(),false));
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int r=0,c=i;
            for(; c<s.size(); r++,c++){
                if(i==0){
                    dp[r][c]=true;
                    ans++;
                }
                else if(i==1){
                    if(s[r]==s[c]){ dp[r][c]=true; ans++;}
                }
                else{
                    if(s[r]==s[c] && dp[r+1][c-1]){ dp[r][c]=true; ans++;}
                }
            }
        }
        return ans;
    }
};