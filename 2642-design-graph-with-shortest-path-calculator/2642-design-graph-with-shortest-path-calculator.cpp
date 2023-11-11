class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        adj= vector<vector<pair<int,int>>>(n);
        for(auto &i: edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
        this->n=n;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});
        vector<int> v(n, INT_MAX);
        v[node1]=0;
        while(!pq.empty()){
            auto x= pq.top();
            pq.pop();
            int a= x.second, b= x.first;
            if(a==node2) return b;
            for(auto &i: adj[a]){
                if(v[i.first]> b+i.second){
                    pq.push({b+i.second, i.first});
                    v[i.first]=b+i.second;
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */