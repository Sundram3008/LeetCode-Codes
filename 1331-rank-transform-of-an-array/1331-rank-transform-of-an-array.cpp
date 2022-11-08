class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(auto i: arr) mp[i]++;
        int cnt=1;
        for(auto &i: mp) i.second=cnt++;
        for(auto &i: arr) i= mp[i];
        return arr;
        
    }
};