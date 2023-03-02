//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void lastTwo(vector<int> &costs, int &fimax, int &fi, int &smax, int &si){
        for(int i=0; i<costs.size(); i++){
            if(costs[i]<=fimax){
                smax= fimax;
                si= fi;
                fimax= costs[i];
                fi= i;
            }else{
                if(smax>costs[i]){
                    smax= costs[i];
                    si=i;
                }
            }
        }
        return;
    }
    int minCost(vector<vector<int>> &costs) {
        if(costs.size()==0 || costs[0].size()==0) return 0;
        int fimax=INT_MAX, smax=INT_MAX, fi=INT_MAX, si=INT_MAX;
        lastTwo(costs[0], fimax, fi, smax, si);
        for(int i=1; i<costs.size(); i++){
            for(int j=0; j<costs[i].size(); j++){
                if(j!=fi && fi!=INT_MAX){
                    costs[i][j]+= fimax;
                }else if(j!=si && si!=INT_MAX){
                    costs[i][j]+= smax;
                }else return -1;
            }
            fimax=INT_MAX, smax=INT_MAX, fi=INT_MAX, si=INT_MAX;
            lastTwo(costs[i], fimax, fi, smax, si);
        }
        int ans=*min_element(costs.back().begin(), costs.back().end());
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends