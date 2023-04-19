//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    void something(string &s, int x){
        int max=-1;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                if(max==-1) max=0;
                max= i+x;
            }
            if(s[i]=='0' && max>=i) s[i]='2';
        }
    }
    bool wifiRange(int n, string s, int x){
        // code here
        
        something(s, x);
        reverse(s.begin(), s.end());
        something(s, x);
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0') return false;
        }
        return true;
    }
    
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends