class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            cnt++;
        }
        for(int j=0; j<t.length(); j++){
            if(mp[t[j]]==0){
                return false;
            }
            mp[t[j]]--;
            cnt--;
        }
        return (cnt==0);
    }
};