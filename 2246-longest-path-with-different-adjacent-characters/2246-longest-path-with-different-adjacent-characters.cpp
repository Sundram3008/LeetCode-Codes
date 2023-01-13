class Solution {
public:
    vector<int> dist = vector<int>(100001); // length store kr rhe 
    void dfs(vector<vector<int>> &adj, int idx, string &s, int &ans){
        dist[idx]=1; // atleast 1 length toh rahega hi (ushi particular node k kaaran)
        for(auto i: adj[idx]){
            dfs(adj, i, s, ans); // dfs kr rhe graph pe
            if(s[idx]!=s[i]){ // check kr rhe ki character different h ya nhi
                ans= max(ans, dist[idx]+ dist[i]); 
                dist[idx]= max(dist[idx], dist[i]+1);
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        int ans=1;
        dfs(adj, 0, s, ans);
        return ans;
    }
};