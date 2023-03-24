//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void help(int k, int idx, vector<int> &temp, vector<vector<int>> &ans, int n){
        if(n==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=idx+1; i<=9; i++){
            if(n>= i){
                temp.push_back(i);
                help(k, i, temp, ans, n-i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        help(K, 0, temp, ans, N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends