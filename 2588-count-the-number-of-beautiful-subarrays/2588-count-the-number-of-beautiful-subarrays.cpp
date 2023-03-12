class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long int ans=0, x=0;
        unordered_map<long , int> mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            x^=nums[i];
            if(mp.find(x)!=mp.end()){
                ans+= mp[x];
            }
            mp[x]++;
        }
        return ans;
    }
};