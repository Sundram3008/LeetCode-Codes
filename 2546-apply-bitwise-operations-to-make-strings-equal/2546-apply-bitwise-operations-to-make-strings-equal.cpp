class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int scn=0, tcn=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1') scn++;
            if(t[i]=='1') tcn++;
        }
        if(scn==0 && tcn==0){
            return true;
        }
        return !(scn==0 || tcn==0);
    }
};