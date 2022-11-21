//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void help(vector<int> &v, int i, int n, int x, set<vector<int>> &ans, vector<int> &temp){
	    if(n==0){
	        ans.insert(temp);
	        return;
	    }if(i==x) return ;
	    if(v[i]<= n){
	        temp.push_back(v[i]);
	        help(v, i, n-v[i], x, ans, temp);
	        temp.pop_back();
	    }
	    help(v, i+1, n, x, ans, temp);
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<int> v(n,0), temp;
        iota(v.begin(), v.end(), 1);
        reverse(v.begin(), v.end());
        set<vector<int>> ans;
        help(v, 0,n,n,ans, temp);
        vector<vector<int>> result;
        for(auto i: ans) result.push_back(i);
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends