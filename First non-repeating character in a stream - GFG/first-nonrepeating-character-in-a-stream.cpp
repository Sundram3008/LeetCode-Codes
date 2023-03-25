//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> freq(26,-1);
		    string ans;
		    for(int i=0; i<A.length(); i++){
		        if(freq[A[i]-'a']==-1) {
		            freq[A[i]-'a']=i;
		        }else{
		            freq[A[i]-'a']=-2;
		        }
		        int mini=A.length();
		        for(int j=0; j<26; j++){
		            if(freq[j]!= -1 && freq[j]!=-2){
		                mini= min(mini, freq[j]);
		            }
		        }
		        if(mini==A.length()) ans.push_back('#');
		        else ans.push_back(A[mini]);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends