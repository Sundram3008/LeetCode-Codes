class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int l=0, l1=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='#') s[l++]=s[i];
            else{
                l= max(0, l-1);
            }
        }
        for(int i=0; i<t.length(); i++){
            if(t[i]!='#') t[l1++]=t[i];
            else{
                l1= max(0, l1-1);
            }
        }
        if(l1!=l) return false;
        for(int i=0; i<l; i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};