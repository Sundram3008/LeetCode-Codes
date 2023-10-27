class Solution {
public:
    void helper(string &s, int &l, int &r, int lf, int rf){
        while(lf>=0 && rf<s.length() && s[lf]==s[rf]){ 
            if(r-l+1 < rf-lf+1){
                r=rf;
                l=lf;
            }
            lf--; 
            rf++;
        }
        return ;
    }
    string longestPalindrome(string s) {
        int l=0, r=0;
        for(int i=0; i<s.length(); i++){
            helper(s, l, r, i, i);
            helper(s, l, r, i, i+1);
        }
        return s.substr(l, r-l+1);
    }
};