//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int j=0, ans=0;
		    vector<int> freq(26,0);
		    for(int i=0; i<s.length(); i++){
		        freq[s[i]-'A']++;
		        int m= *max_element(freq.begin(), freq.end());
		        if(i-j+1-m >k) {
		            freq[s[j]-'A']--;
		            j++;
		        }else ans= max(i-j+1, ans);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends