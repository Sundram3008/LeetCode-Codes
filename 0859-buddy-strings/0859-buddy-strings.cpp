class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.length()!= g.length()) return false;
        vector<int> v(26, 0), v1(26, 0);
        bool yup=false;
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            v[s[i]-'a']++;
            v1[g[i]-'a']++;
            if(v[s[i]-'a']>=2) yup=true;
            if(s[i]!= g[i]){
                cnt++;
            }
        }
        for(int i=0; i<26; i++){
            if(v[i]!=v1[i]) return false;
        }
        return (cnt==2 || (cnt==0 && yup));
    }
};