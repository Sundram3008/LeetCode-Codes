class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n= s.length();
        if(n<=2) return n;
        int l=0, ans=0, prev=0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                if(prev) l=prev;
                prev= i;
            }
            ans= max(ans, i-l+1);
        }
        return ans;
    }
};