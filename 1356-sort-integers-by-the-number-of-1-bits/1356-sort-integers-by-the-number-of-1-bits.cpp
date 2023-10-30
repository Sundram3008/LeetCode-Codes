class Solution {
public:
    static bool myComp(pair<int, int> &a, pair<int, int> &b){
        if(a.second != b.second) return a.second< b.second;
        return a.first < b.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> bav;
        for(int i=0; i<arr.size(); i++){
            bav.push_back({arr[i], __builtin_popcount(arr[i])});
        }
        sort(bav.begin(), bav.end(), myComp);
        vector<int> ans;
        for(int i=0; i<bav.size(); i++) ans.push_back(bav[i].first);
        return ans;
    }
};