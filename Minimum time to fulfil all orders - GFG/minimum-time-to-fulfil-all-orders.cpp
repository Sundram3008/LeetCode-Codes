//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isPossible(vector<int> &a, int n, long long mins){
        int cnt=0;
        for(auto &i: a){
            long long tot=i, c=1;
            while(tot<=mins){
                c++;
                tot+= (c*i);
                cnt++;
            }
        }
        return (cnt>=n);
    }
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        long long r=INT_MAX, l=1, ans=0;
        while(l<r){
            long long mid= l+ ((r-l)/2);
            if(isPossible(A,N, mid)){
                r=mid;
                ans= mid;
            }else l=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends