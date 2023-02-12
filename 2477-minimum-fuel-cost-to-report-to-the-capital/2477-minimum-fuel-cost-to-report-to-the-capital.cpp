class Solution {
public:
    long long fuel=0;
    int dfs(int node, vector<vector<int>> &graph, int k, vector<bool> &vis){
        int val=1;
        for(auto i: graph[node]){
            if(!vis[i]){
                vis[i]=true;
                int x= dfs(i, graph, k, vis);
                val+= x;
            }
        }
        if(node!=0){
            fuel+= ceil((val*1.0)/k);
        }
        return val;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    
        int n= roads.size()+1;
        if(n<=2) return n-1;
        vector<bool> vis(n,false);
        vector<vector<int>> graph(n);
        for(auto i: roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        // for(auto i: graph){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vis[0]=true;
        dfs(0, graph, seats, vis);
        return fuel;
    }
};