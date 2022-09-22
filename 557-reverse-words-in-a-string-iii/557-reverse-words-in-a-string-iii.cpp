class Solution {
public:
    string reverseWords(string s) {
        string ans="", temp="";
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }else {
                ans= " "+temp+ans;
                temp="";
            }
        }
        ans=temp+ans;
        return ans;
    }
};