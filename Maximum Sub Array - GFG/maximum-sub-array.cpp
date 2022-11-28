//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int l=-1, s=0,r=-1, sum=0, msum=0, i=0;
	    for(i=0; i<n; i++){
	        if(a[i]<0){
	            s=i+1;
	            sum=0;
	        }else{
	            sum+= a[i];
	        }
	        if(sum>= msum){
	            if(sum == msum){
	                if(r-l+1 < i-s+1){
	                    l=s;
	                    r=i;
	                }
	            }
	            else {
	                msum= sum;
	                l=s;
	                r=i;
	            }
	        }
	    }
	    if(l==-1 && r== -1) return {-1};
	    vector<int> ans;
	    for(int i=l; i<=r; i++){
	        ans.push_back(a[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends