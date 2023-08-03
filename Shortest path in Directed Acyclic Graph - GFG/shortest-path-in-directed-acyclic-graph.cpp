//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<int>> graph(N);
        map<pair<int,int>, int> mp;
        for(int i=0; i<M; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            int x= edges[i][0], y= edges[i][1], z= edges[i][2];
            mp[{x,y}] = z;
        }
        vector<int> ans(N, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        ans[0]=0;
        while(!pq.empty()){
            int dist= pq.top().first, node= pq.top().second;
            pq.pop();
            for(auto i: graph[node]){
                if(ans[i]== -1 || (ans[i] > (dist+ mp[{node, i}])) ){
                    ans[i]= dist+ mp[{node, i}];
                    pq.push({dist+ mp[{node, i}], i});
                }
           }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends