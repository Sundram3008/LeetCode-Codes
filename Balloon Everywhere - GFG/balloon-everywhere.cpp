//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> v(26,0);
        int ans=INT_MAX;
        for(auto i: s){
            v[i-'a']++;
        }
        for(int i=0; i<26; i++){
            if(i+'a'=='b'){
                ans= min(ans, v[i]);
            }else if(i+'a'=='a'){
                ans= min(ans, v[i]);
            }else if(i+'a'=='l'){
                ans= min(ans, v[i]/2);
            }else if(i+'a'=='o'){
                ans= min(ans, v[i]/2);
            }else if(i+'a'=='n'){
                ans= min(ans, v[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends