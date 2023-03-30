class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        if(mp.find(s1+s2)!=mp.end()) return mp[s1+s2];
        vector<int> freq(26,0);
        for(auto &i: s1) freq[i-'a']++;
        for(auto &i: s2) freq[i-'a']--;
        for(auto &i: freq){
            if(i!=0) return false;
        }
        
        int n= s1.length();
        for(int i=1; i<=n-1; i++){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))){ 
                mp[s1+s2]=true;
                return true;
            }
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))){ 
                mp[s1+s2]=true;
                return true;
            }
        }
        mp[s1+s2]=false;
        return false;
    }
};