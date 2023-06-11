class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n= s.length();
        if(n<=2) return n;
        int l=0, ans=0, cnt=0, prev=0, prev2=0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                prev2=prev;
                prev=i;
                cnt++;
            }
            if(cnt>1){
                l=prev2;
                cnt=1;
            }
            ans= max(ans, i-l+1);
        }
        return ans;
    }
};