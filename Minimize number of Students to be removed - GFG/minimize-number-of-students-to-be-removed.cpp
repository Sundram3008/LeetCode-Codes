//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // code here
        vector<int> dp;
        for(int i=0; i<n; i++){
            int j=0;
            while(j<dp.size() && dp[j]<h[i]) j++;
            if(j==dp.size()) dp.push_back(h[i]);
            else dp[j]= h[i];
        }
        return n-dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends