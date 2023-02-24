class Solution {
public:
    bool checkZeroOnes(string s) {
        int currz=0, lzero=0, curro=0, lone=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                currz=0;
                curro++;
                lone= max(lone, curro);
            }else{
                curro=0;
                currz++;
                lzero= max(lzero, currz);
            }
        }
        return lone> lzero;
    }
};