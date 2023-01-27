//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        // Code here
        vector<int> dist(v,100000000);
        dist[s]=0;
        for(int i=1; i<= v-1; i++){
            for(auto j: edges){
                if(dist[j[0]]!= 100000000 && dist[j[0]]+j[2]< dist[j[1]])
                    dist[j[1]]=dist[j[0]]+j[2];
            }
        }
        for(auto j: edges){
            if(dist[j[0]]!= INT_MAX && dist[j[0]]+j[2]< dist[j[1]])
                return {-1};
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends