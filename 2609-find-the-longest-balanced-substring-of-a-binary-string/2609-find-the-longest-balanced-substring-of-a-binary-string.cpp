class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if((j-i+1) %2==0){
                    int l=i, r= j;
                    bool f=true;
                    while(l<r){
                        if(s[l]=='1'){
                            f=false;
                            break;
                        }
                        if(s[r]=='0'){
                            f=false;
                            break;
                        }
                        l++, r--;
                    }
                    if(f) ans= max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};