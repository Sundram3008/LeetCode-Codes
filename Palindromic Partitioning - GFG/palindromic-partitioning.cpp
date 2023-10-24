//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(string str){
        int l=0, r= str.length()-1;
        while(l<r){
            if(str[l]!= str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int helper(int idx, string &str, vector<int> &dp){
        if(idx >= str.length()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        int val=INT_MAX;
        for(int j=idx; j<str.length(); j++){
            temp.push_back(str[j]);
            if(isPal(temp)){
                val = min(val, 1+helper(j+1, str, dp));
            }
        }
        dp[idx]= val;
        return val;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.length(), -1);
        return helper(0, str, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends