class Solution {
public:
    string sortSentence(string s) {
        map<int, string> mp;
        string str="";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='0' && s[i]<='9') {
                mp[s[i]-'0']= str;
                str="";
            }
            else if(s[i]!=' '){
                str+=s[i];
            }
        }
        string ans="";
        for(auto i: mp){
            ans+= i.second+" ";
        }
        ans.pop_back();
        return ans;
    }
};