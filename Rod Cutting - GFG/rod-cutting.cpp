//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    // int ans=0;
    // void helper(int p[], int x, int n, int val){
    //     if(n==0){
    //         ans= max(ans, val);
    //         return ;
    //     }
    //     for(int i=0; i<x; i++){
    //         if(i+1<=n){
    //             helper(p, x, n-i-1, val+p[i]);
    //         }
    //     }
    //     return ;
    // }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(j>=i) dp[i][j]= max(dp[i-1][j], dp[i][j-i]+ price[i-1]);
                else dp[i][j]= dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends