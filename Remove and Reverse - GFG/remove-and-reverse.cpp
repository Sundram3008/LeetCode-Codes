//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        int cnt=0, l=0, r= s.length()-1;
        vector<int> freq(26,0);
        for(auto i: s) freq[i-'a']++;
        while(l<r){
            if(cnt%2==0){
                if(freq[s[l]-'a']>1){
                    freq[s[l]-'a']--;
                    s[l]='*';
                    cnt++;
                }
                l++;
            }else{
                if(freq[s[r]-'a']>1){
                    freq[s[r]-'a']--;
                    s[r]='*';
                    cnt++;
                }
                r--;
            }
        }
        string ans="";
        if(cnt%2){
            for(int i=s.length()-1; i>=0; i--){
                if(s[i]!='*') ans.push_back(s[i]);
            }
        }
        else{
            for(int i=0; i<s.length(); i++){
                if(s[i]!='*') ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends