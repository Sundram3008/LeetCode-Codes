//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
         vector<int>v(K,0);
        for(int i=0;i<N;i++)
            v[arr[i]%K]++;
        int i=1;
        int j=K-1;
        int ans=0;
        while(i<j){
            ans+=max(v[i],v[j]);
            i++;
            j--;
        }
        if(i==j)
            if(v[i]>0)ans++;
        if(v[0]>0)ans++;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends