class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        unordered_map<string, bool> mp;
        for(auto i: connections) {
            string x= to_string(i[0]) + " - " + to_string(i[1]);
            mp[x]=true;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int ans=0;
        while(!q.empty()){
            int idx= q.front();
            q.pop();
            for(auto i: adj[idx]){
                if(!vis[i]){
                    string x= to_string(i) + " - " + to_string(idx);
                    if(!mp[x]) ans++;
                    mp[x]=true;
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        return ans;
    }
};