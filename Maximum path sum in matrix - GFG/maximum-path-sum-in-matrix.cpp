//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(vector<vector<int>> &mx, int n, int m, int r, int c, vector<vector<int>> &dp){
        if(r<0 || c<0 || c>=m) return -1e9;
        if(r==0)  return mx[r][c];
        if(dp[r][c]!=INT_MIN) return dp[r][c];
        int down= mx[r][c] + dfs(mx, n, m, r-1, c, dp);
        int ld= mx[r][c] + dfs(mx, n, m, r-1, c-1, dp);
        int rd= mx[r][c] + dfs(mx, n, m, r-1, c+1, dp);
        dp[r][c]= max({down, ld, rd});
        return dp[r][c];
    }
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int n= matrix.size(), m= matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,INT_MIN));
        int ans=INT_MIN;
        for(int i=0; i<m; i++){
            ans= max(ans, dfs(matrix, n, m, n-1, i, dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends