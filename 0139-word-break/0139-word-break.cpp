class Solution {
public:
    bool helper(int idx, string &s, unordered_set<string> &dict, unordered_map<int, bool> &dp){
        if(idx==s.length()) return true;
        if(dp.find(idx)!= dp.end()) return dp[idx];
        string word="";
        bool poss= false;
        for(int i=idx; i<s.length(); i++){
            word.push_back(s[i]);
            if(dict.find(word)!=dict.end() ){ 
                poss|= helper(i+1, s, dict, dp);
            }
        }
        return dp[idx]=poss;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_map<int, bool> dp;
        for(auto i: wordDict) dict.insert(i);
        return helper(0, s, dict, dp);
    }
};