//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countPalinInRange (int n, string A, int q1, int q2);
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int q1, q2; cin >> q1 >> q2;
		cout << countPalinInRange (n, s, q1, q2) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int totalPals(string &s, int n, int q1, int q2, int l, int r){
    int pals=0;
    while(l>=q1 && r<=q2 && s[l]==s[r]){
        pals++;
        l--;
        r++;
    }
    return pals;
}
int countPalinInRange (int n, string s, int q1, int q2)
{
    // your code here
    int ans=0;
    int from= min(q1, q2), to= max(q1, q2);
    for(int i=from; i<=to; i++){
        ans+=totalPals(s, n, from, to, i, i);
        ans+=totalPals(s, n, from, to, i, i+1);
    }
    return ans;
}