class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // unordered_set<string> res;
        // vector<char> v= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        // for(int i=0; i<26; i++){
        //     for(int j=0; j<26; j++){
        //         bool y1=false, y2=false;
        //         for(int k=0; k<s.length(); k++){
        //             if(y1==false && v[i]==s[k]) y1=true;
        //             else if(y1 && y2==false && v[j]==s[k]) y2=true;
        //             else if(y1 && y2 && v[i]==s[k]) {
        //                 string x;
        //                 x.push_back(v[i]);
        //                 x.push_back(v[j]);
        //                 x.push_back(s[k]);
        //                 res.insert(x);
        //             }
        //         }
        //     }
        // }
        // return res.size();
        int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
    for (int i = 0; i < s.size(); ++i) {
        first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
        last[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i)
        if (first[i] < last[i])
            res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
    return res;
    }
};