//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void dfs(vector<vector<int>> &m, int i, int j, int n, string s){
        if(i==n-1 && j==n-1) {
            ans.push_back(s);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]!=1) return;
        m[i][j]=-1;
        s.push_back('U');
        dfs(m, i-1, j, n, s);
        s.pop_back();
        s.push_back('L');
        dfs(m, i, j-1, n, s);
        s.pop_back();
        s.push_back('D');
        dfs(m, i+1, j, n ,s);
        s.pop_back();
        s.push_back('R');
        dfs(m, i, j+1, n, s);
        s.pop_back();
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==1)
        dfs(m,0,0,n,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends