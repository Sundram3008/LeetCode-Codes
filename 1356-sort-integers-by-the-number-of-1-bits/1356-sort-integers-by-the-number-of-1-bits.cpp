class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> mp;
        for(int i=0; i<arr.size(); i++){
            mp[__builtin_popcount(arr[i])].insert(arr[i]);
        }
        vector<int> ans;
        for(auto i: mp){
            for(auto j: i.second) ans.push_back(j);
        }
        return ans;
    }
};