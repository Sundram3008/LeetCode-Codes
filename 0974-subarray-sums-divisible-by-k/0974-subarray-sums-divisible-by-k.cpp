class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum=0,ans=0;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            int key= sum%k;
            if(key<0) key+=k;
            ans+= mp[key];
            mp[key]++;
        }
        return ans;
    }
};