class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        for (const vector<int>& road : roads) {
            adj[road[0]].emplace_back(road[1]);
            adj[road[1]].emplace_back(road[0]);
        }

        int ret = 0;

        for (int city1 = 0; city1 < n; city1++) {
            for (int city2 = city1 + 1; city2 < n; city2++) {
                int rating = adj[city1].size() + adj[city2].size();

                auto it = find(adj[city1].begin(), adj[city1].end(), city2);
                if (it != adj[city1].end())
                    rating--;

                ret = max(rating, ret);
            }
        }
        return ret;
    }
};