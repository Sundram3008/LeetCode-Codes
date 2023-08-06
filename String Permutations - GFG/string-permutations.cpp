//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void perms(string &s, vector<bool> &tl, vector<string> &ans, string &temp){
        if(temp.length()==s.length()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i<s.length(); i++){
            if(tl[i]==false){
                temp.push_back(s[i]);
                tl[i]=true;
                perms(s, tl, ans, temp);
                temp.pop_back();
                tl[i]=false;
            }
        }
    }
    vector<string> permutation(string S)
    {
        vector<bool> takenList(S.length(), false);
        vector<string> ans;
        string temp="";
        perms(S, takenList, ans, temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends