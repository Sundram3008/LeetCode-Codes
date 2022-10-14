//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        map<int,int> mp;
        for(int i=0; i<n; i++) mp[a[i]]++;
        int ans=0;
        for(auto i= mp.rbegin(); i!= mp.rend(); i++){
            ans+= ((i->first) * (i->second));
            int val= i->second, x= i->first;
            if(mp.find(x-1)!= mp.end()){
                mp[x-1]-=val;
                if(mp[x-1]<=0) mp.erase(x-1);
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends