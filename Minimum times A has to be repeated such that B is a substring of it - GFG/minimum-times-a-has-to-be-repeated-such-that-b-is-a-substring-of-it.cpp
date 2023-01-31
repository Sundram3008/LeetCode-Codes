//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        string x= a;
        int cnt=1;
        while(x.length()<=b.length()){ 
            if(x.length()== b.length() && x==b) return cnt;
            x+= a;
            cnt++;
        }
        for(int i=0; i<x.length(); i++){
            int j=0, k=i;
            while(j<b.length() && k<x.length() && x[k]==b[j]){
                j++;
                k++;
            }
            if(j== b.length()) return cnt;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends