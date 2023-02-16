//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    int dfs(vector<int> &arr, int n, int idx, vector<int> &codn){
        if(idx>=n || idx<0) return 2;
        if(codn[idx]>0){
            //codn[idx]=1;
            return codn[idx];
        }
        codn[idx]=1;
        int x= dfs(arr, n, idx+arr[idx], codn);
        return codn[idx]=x;
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> codn(n,0);
        for(int i=0; i<n; i++){
            if(codn[i]==0){
                codn[i]=dfs(arr,n,i,codn);
            }
        }
        int ans=0;
        for(int i=0; i<n; i++) if(codn[i]==2) ans++;
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends