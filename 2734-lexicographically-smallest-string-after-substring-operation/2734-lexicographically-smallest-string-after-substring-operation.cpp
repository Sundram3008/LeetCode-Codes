class Solution {
public:
    string smallestString(string s) {
        int l=0, r=0, n= s.length();
        bool f=false;
        while(l<n && s[l]=='a') l++;
        r=l;
        while(r<n){
            if(s[r]!='a'){
                s[r++]--;
                f=true;
            }else break;
        }
        if(!f){
            s[n-1] = (s.back()=='a')? s[n-1]='z': s[n-1]--;
        }
        return s;
    }
};