class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        string str="~";
        for(int i=0; i<dict.size(); i++){
            int k=0;
            for(int j=0; j<s.length() && k<dict[i].size(); j++){
                if(s[j]==dict[i][k]){
                    k++;
                }
            }
            if(k==dict[i].size()){
                if(str.size()<=dict[i].size()){
                    if(str.size()==dict[i].size()){
                        if(str> dict[i]) str=dict[i];
                    }
                    else str=dict[i];
                }
            }
        }
        if(str=="~") return "";
        return str;
    }
};