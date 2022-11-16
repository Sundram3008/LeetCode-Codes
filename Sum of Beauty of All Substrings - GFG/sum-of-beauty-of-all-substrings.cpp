//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans=0;
        for(int i=0; i<s.size(); i++){
            vector<int> v(26,0);
            for(int j=i; j<s.size(); j++){
                v[s[j]-'a']++;
                int maxi=0, mini=INT_MAX;
                for(int i=0; i<26; i++){
                    if(v[i]<mini && v[i]!=0) mini=v[i];
                    if(v[i]>maxi) maxi=v[i];
                }
                ans+= maxi-mini;
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends