class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                if(i<s.length()/2){
                    cnt++;
                }else cnt--;
            }
        }
        return cnt==0;
    }
};