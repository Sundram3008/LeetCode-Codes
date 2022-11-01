class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, pair<int, map<int,set<string>>>> mp;
        long maxval=0;
        for(int i=0; i<ids.size(); i++){
            mp[creators[i]].first+= views[i];
            if(mp[creators[i]].first>maxval) maxval= mp[creators[i]].first;
            mp[creators[i]].second[views[i]].insert(ids[i]);
        }
        vector<vector<string>> ans;
        for(auto i: mp){
            if(i.second.first==maxval){
                auto x= i.second.second.end();
                --x;
                auto t= x->second.begin();
                ans.push_back({i.first, *t});
            }
        }
        return ans;
    }
};