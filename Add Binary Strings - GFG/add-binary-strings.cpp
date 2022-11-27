//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    string ans="";
	    int i=A.size()-1, j= B.size()-1, carry=0;
	    while(i>=0 && j>=0){
	        int val= carry+ A[i]-'0'+ B[j]-'0';
	        i--;
	        j--;
	        if(val%2==0) ans.push_back('0');
	        else ans.push_back('1');
	        if(val==2 || val==3) carry=1;
	        else carry=0;
	    }
	    while(i>=0){
	        int val= carry+ A[i]-'0';
	        i--;
	        if(val%2==0) ans.push_back('0');
	        else ans.push_back('1');
	        if(val==2 || val==3) carry=1;
	        else carry=0;
	    }
	    while(j>=0){
	        int val= carry+ B[j]-'0';
	        j--;
	        if(val%2==0) ans.push_back('0');
	        else ans.push_back('1');
	        if(val==2 || val==3) carry=1;
	        else carry=0;
	    }
	    if(carry>0) ans.push_back('1');
	    while(ans.size() >0 && ans.back()=='0') ans.pop_back();
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends