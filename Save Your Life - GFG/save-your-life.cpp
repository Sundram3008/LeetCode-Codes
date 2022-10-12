//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
            unordered_map<char,int> mp;
            int alpha=65;
            for(int i=0; i<26; i++){
                mp[char(alpha)]= alpha++;
            }
            alpha=97;
            for(int i=0; i<26; i++){
                mp[char(alpha)]= alpha++; 
            }
            for(int i=0; i<n; i++)
                mp[x[i]]=b[i];
            int curr=0,ans=INT_MIN;
            string str="",ansstr="";
            for(int i=0; i<w.size(); i++){
                curr+= mp[w[i]];
                str+= w[i];
                if(curr>ans){ 
                    ans=curr;
                    ansstr=str;
                }
                if(curr<0){ 
                    curr=0;
                    str="";
                }
            }
            return ansstr;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends