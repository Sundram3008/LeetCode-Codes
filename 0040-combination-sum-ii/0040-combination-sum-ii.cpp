class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void rec(vector<int> &v, int i, int k, vector<int> temp){
        if(i>= v.size()){
            if(k==0){
                st.insert(temp);
            }
            return;
        }
        if(k>=v[i]){
            temp.push_back(v[i]);
            rec(v, i+1, k-v[i], temp);
            temp.pop_back();
        }
        int x= v[i];
        while(i<v.size() && x==v[i]) i++;
        rec(v, i, k, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        rec(candidates, 0, target, temp);
        for(auto i: st) ans.push_back(i);
        return ans;
    }
    
};