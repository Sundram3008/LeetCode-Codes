class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int idx, int &cnt){
        for(auto &i: adj[idx]){
            if(!vis[i]){
                vis[i]=true;
                cnt++;
                dfs(adj, vis, i, cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        vector<int> clusters;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int cnt=1;
                vis[i]=true;
                dfs(adj, vis, i, cnt);
                clusters.push_back(cnt);
            }
        }
        long long total= accumulate(clusters.begin(), clusters.end(),0), ans=0;
        for(auto c: clusters){
            cout<<c<<" ";
            total-= c;
            ans+= (1LL* c* total);
        }
        return ans;
    }
};