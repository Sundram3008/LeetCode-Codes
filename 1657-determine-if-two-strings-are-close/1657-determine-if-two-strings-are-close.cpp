class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!= word2.size()) return false;
        vector<int> v(26,0), v1(26,0), p(26,0), p1(26,0);
        unordered_map<int,bool> mp;
        for(char i: word1){ v[i-'a']++; p[i-'a']=1;}
        for(char i: word2){ v1[i-'a']++; p1[i-'a']=1;}
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());
        return (v==v1)&& (p==p1);
    }
};