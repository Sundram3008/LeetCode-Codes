class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        int val=0;
        for(int i=0; i<flowers.size(); i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
        for(auto &i: mp){
            val+= i.second;
            mp[i.first]=val;
        }
        mp[-1]=0;
        vector<int> ans(people.size(), 0);
        for(int i=0; i<people.size(); i++){
            auto it= mp.lower_bound(people[i]);
            if(it->first == people[i]) ans[i]= it->second;
            else ans[i]= (--it)->second;
        }
        return ans;
    }
};