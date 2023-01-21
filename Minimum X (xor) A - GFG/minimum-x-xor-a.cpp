//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int i=0;
        vector<int> bits(32,0), nbits(32,0);
        while(a>0){
            bits[i++]= a%2;
            a/=2;
        }
        int ones= __builtin_popcount(b);
        for(int i=bits.size()-1; i>=0 && ones>0; i--){
            if(bits[i]==1){
                nbits[i]=1;
                ones--;
            }
        }
        for(int i=0; i<nbits.size() && ones>0; i++){
            if(nbits[i]!=1) nbits[i]=1, ones--;
        }
        int ans=0;
        for(int i=0; i<32; i++){
            ans+= (nbits[i]*pow(2,i));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends