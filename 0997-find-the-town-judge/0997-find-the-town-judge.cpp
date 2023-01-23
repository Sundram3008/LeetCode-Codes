class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n,0), t(n,0);
        for(auto i: trust){
            v[i[1]-1]++;
            t[i[0]-1]++;
        }
        for(int i=0; i<n; i++){
            if(v[i]==n-1 && t[i]==0) return i+1;
        }
        return -1;
    }
};