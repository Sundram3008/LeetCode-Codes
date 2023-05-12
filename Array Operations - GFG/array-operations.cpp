//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int cnt=0, z=0;
        for(int i=0; i<n; i++) if(arr[i]==0) z++;
        if(z==0) return -1;
        for(int i=0; i<n; i++){
            bool flag=false;
            while(i<n && arr[i]!=0){
                i++;
                flag=true;
            }
            if(flag) cnt++;
        }
        return cnt;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends