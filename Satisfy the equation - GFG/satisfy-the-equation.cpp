//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        if(N<4) return {-1,-1,-1,-1};
        unordered_map<int, set<pair<int,int>>> mp;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                mp[A[i]+A[j]].insert(make_pair(i,j));
            }
        }
        for(int i=0; i<N; i++){
            for(int j= i+1; j<N; j++){
                if(mp.find(A[i]+A[j])!=mp.end()){
                    for(auto k: mp[A[i]+A[j]]){
                        if(k.first!= i && k.first!= j && k.second!= j && k.second!=i){
                            return {i,j,k.first, k.second};
                        }
                    }
                }
            }
        }
        return {-1,-1,-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends