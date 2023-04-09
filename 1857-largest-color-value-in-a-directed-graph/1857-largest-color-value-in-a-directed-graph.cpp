class Solution {
public:
    
//     void dfs(string &colors, vector<vector<int>> &adj, int idx, vector<bool> &curvis, vector<bool> &vis, int &val, vector<int> &freq, int &x){
//         if(curvis[idx]==true && vis[idx]==true){
//             x= -1;
//             return ;
//         }
//         curvis[idx]=true;
//         vis[idx]=true;
//         freq[colors[idx]-'a']++;
//         for(int i=0; i<26; i++){
//             val= max(val, freq[i]);
//         }
//         for(int i=0; i<adj[idx].size(); i++){
//             dfs(colors, adj, adj[idx][i], curvis, vis, val, freq, x);
//             if(x==-1) return ;
//         }
//         freq[colors[idx]-'a']--;
//         vis[idx]=false;
//     }
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//         int n= colors.size(), ans=-1;
//         vector<bool> vis(n, false);
//         vector<vector<int>> adj(n);
//         for(int i=0; i<edges.size(); i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//         }
//         int x=0;
//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 vector<bool> currvis(n, false);
//                 vector<int> freq(26,0);
//                 int val=0;
//                 dfs(colors, adj, i, currvis, vis, val,freq, x);
//                 if(x!= -1){
//                     ans= max(ans, val);
//                 }else return -1;
//             }
//         }
//         return ans;
//     }
    int dfs(int i, string &c, vector<vector<int>> &al, vector<vector<int>> &cnt, vector<int> &visited) {
    if (!visited[i]) {
        visited[i] = 1;
        for (auto j : al[i]) {
            if (dfs(j, c, al, cnt, visited) == INT_MAX)
                return INT_MAX;
            for (auto k = 0; k < 26; ++k)
                cnt[i][k] = max(cnt[i][k], cnt[j][k]);
        }
        ++cnt[i][c[i] - 'a'];
        visited[i] = 2;
    }
    return visited[i] == 2 ? cnt[i][c[i] - 'a'] : INT_MAX;
}
int largestPathValue(string c, vector<vector<int>>& edges) {
    vector<vector<int>> al(c.size()), cnt(c.size(), vector<int>(26));
    vector<int> visited(c.size());
    for (auto &e : edges)
        al[e[0]].push_back(e[1]);
    int res = 0;
    for (auto i = 0; i < c.size() && res != INT_MAX; ++i)
        res = max(res, dfs(i, c, al, cnt, visited));
    return res == INT_MAX ? -1 : res;
}
};