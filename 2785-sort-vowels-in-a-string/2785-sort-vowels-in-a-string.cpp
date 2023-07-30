class Solution {
public:
    bool isvow(char c){
        return ((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u') || (c=='A') || (c=='E') || (c=='I')|| (c=='O') || (c=='U'));
    }
    string sortVowels(string s) {
        vector<char> vch;
        for(char i: s){
            if(isvow(i)){
                vch.push_back(i);
            }
        }
        sort(vch.begin(), vch.end());
        int j=0;
        for(int i=0; i<s.length(); i++){
            if(isvow(s[i])){
                s[i]= vch[j++];
            }
        }
        return s;
    }
};