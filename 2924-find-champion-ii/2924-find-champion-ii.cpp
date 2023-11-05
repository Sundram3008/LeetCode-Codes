class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(auto i: edges) st.insert(i[1]);
        if(st.size()!= n-1) return -1;
        for(int i=0; i<n; i++){
            if(st.find(i)==st.end()) return i;
        }
        return -1;
    }
};