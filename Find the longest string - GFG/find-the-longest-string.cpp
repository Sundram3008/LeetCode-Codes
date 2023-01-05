//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string, bool> mp;
        for(auto i: words) mp[i]=true;
        int len=0;
        string ans="";
        for(auto i: words){
            if(len<= i.size()){
                bool flag=true;
                string temp="";
                for(int j=0; j<i.size(); j++){
                    temp+= i[j];
                    if(!mp[temp]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    if(len<i.size()){
                        ans= i;
                        len= i.size();
                    }else{
                        if(ans>i){
                            ans=i;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends