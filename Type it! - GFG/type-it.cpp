//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int cnt=0, ans=s.size();
        string x="";
        for(int i=0; i<s.size(); i++){
            string t= s.substr(i, x.size());
            if(x==t){
                int v= int(x.size())+int(t.size());
                ans= min(ans,int(x.size())+1+ int(s.size())-v);
            }
            x.push_back(s[i]);
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
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends