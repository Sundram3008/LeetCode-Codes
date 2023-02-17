//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> nums) {
        // code here
        //if(k==1) return nums[0];
        long long int total=0, l=0;
        vector<long long > temp(n,0);
        for(int i=0; i<k; i++){
            temp[i]=nums[i];
            total+= nums[i];
        }
        
        for(int i=k; i<n; i++){
            temp[i]=total;
            total-= temp[l];
            total+=temp[i];
            l++;
        }
        return temp.back();
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends