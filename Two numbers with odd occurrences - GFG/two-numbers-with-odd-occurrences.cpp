//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        ll xxor=0;
        for(int i=0; i<N; i++) xxor^=Arr[i];
        ll mask= xxor & (-xxor), x=0,y=0;
        for(int i=0; i<N; i++){
            if((Arr[i]&mask)==0) x^=Arr[i];
            else y^=Arr[i];
        }
        if(x>y) return {x,y};
        else return {y,x};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends