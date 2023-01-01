class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> mp;
        vector<int> ch(26, 0);
        int j=0;
        istringstream ss (s);
        for(string token; ss>>token; ++j){
            if(j==pattern.size() || ch[pattern[j]-'a']!=mp[token]) return false;
            ch[pattern[j]-'a']= mp[token]= j+1;
        }
        return j==pattern.size();
        
    }
};