//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        unordered_map<string, char> mp;
        mp["RB"]='G', mp["BG"]='R', mp["GR"]='B', mp["BR"]='G', mp["GB"]='R', mp["RG"]='B';
        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(a[i]);
            while(st.size()>=2){
                char x= st.top();
                st.pop();
                char x2= st.top();
                st.pop();
                if(x==x2){
                    st.push(x);
                    st.push(x2);
                    break;
                }
                else{
                    string c="";
                    c.push_back(x);
                    c.push_back(x2);
                    st.push(mp[c]);
                }
            }
        }
        return (st.size()%2==0)?2:1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends