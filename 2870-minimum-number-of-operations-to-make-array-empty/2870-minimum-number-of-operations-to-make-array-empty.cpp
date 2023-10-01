class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i: nums) mp[i]++;
        int ans=0;
        for(auto &i: mp){
            int val= i.second;
            if(val==1) return -1;
            ans+= (val/3);
            if(val%3!=0) ans++;
        }
        return ans;
    }
};