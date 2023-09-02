class Solution {
public:
    int helper(string &s, int idx, unordered_map<string, bool> &dict,  vector<int> &dp){
        if(idx==s.length() || dict.find(s.substr(idx))!=dict.end()) return 0;
        if(dp[idx]!= INT_MAX) return dp[idx];
        int ans=s.size();
        string x="";
        for(int i=idx; i<s.length(); i++){
            x.push_back(s[i]);
            int cnt=0;
            if(dict.find(x)==dict.end()) cnt+= (i-idx+1);
            cnt+= helper(s, i+1, dict, dp);
            ans= min(ans, cnt);
        }
        dp[idx]= ans;
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, bool> dict;
        for(auto &i: dictionary) dict[i]=true;
        vector<int> dp(s.size(), INT_MAX);
        return helper(s, 0, dict, dp);
    }
};