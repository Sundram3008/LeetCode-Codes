//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool bfs(vector<vector<int>> &adj, int idx, int v, vector<bool> &vis, vector<bool> &v2){
        queue<int> q;
        q.push(idx);
        vis[idx]=true;
        bool flag= true;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(adj[i].size()!= adj[idx].size()) flag=false;
            for(int j=0; j<adj[i].size(); j++){
                if(!v2[adj[i][j]]) flag=false;
                if(!vis[adj[i][j]]){
                    vis[adj[i][j]]=true;
                    q.push(adj[i][j]);
                }
            }
        }
        return flag;
    }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(v+1, false);
        int cnt=0;
        for(int i=1; i<=v; i++){
            if(!vis[i]){
                vector<bool> v2(v+1, false);
                v2[i]=true;
                for(auto j: adj[i]) v2[j]=true;
                if(bfs(adj, i, v, vis, v2))
                cnt++;
                //cout<<i<<endl;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends