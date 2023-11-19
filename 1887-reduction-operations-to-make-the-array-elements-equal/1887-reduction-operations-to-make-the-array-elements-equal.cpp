class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums) mp[i]++;
        int ans=0;
        while(mp.size()>1){
            auto x= *(--mp.end());
            ans+= x.second;
            mp.erase(x.first);
            auto t= *(--mp.end());
            mp[t.first]+= x.second;
        }
        return ans;
    }
};