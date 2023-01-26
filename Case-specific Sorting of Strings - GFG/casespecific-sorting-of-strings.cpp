//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string s2= str;
        sort(s2.begin(), s2.end());
        int j=0, k=0;
        for(int i=0; i<n; i++){
            if(s2[i]>'Z'){
                j=i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(str[i]<='Z' && str[i]>='A'){
                str[i]= s2[k++];
            }else{
                str[i]= s2[j++];
            }
        }
        return str;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends