//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        if(N==1) return 0;
        if(N==2) return 3;
        long long int l=0, sl=3, mod= 1e9+7;
        for(int i=3; i<=N; i++){
            long long int x= 2*sl+ 3*l;
            x%=mod;
            l=sl;
            sl=x;
        }
        return sl;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends