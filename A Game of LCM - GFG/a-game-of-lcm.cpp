//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long maxGcd(int n) {
        // code here
        long long ans= n*(n-1), cnt=0;
        for(long long i= n-2; i>2 && cnt<2; i--){
            if(__gcd(ans,i)==1){
                ans*=i;
                cnt++;
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
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends