class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) v.push_back(i);
        }
        if(v.size()<=1) return v.size();
        long long int ans=0;
        int mod= 1e9+7;
        int diff= v[1]-v[0];
        ans= diff;
        for(int i=2; i<v.size(); i++){
            int diff= v[i]-v[i-1];
            ans*= diff;
            ans%=mod;
        }
        if(ans==0) return 1;
        return ans;
    }
};