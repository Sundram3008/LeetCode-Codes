class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> mp;
        long long total=0;
        for(int i=0; i<nums.size(); i++){
            total+= nums[i];
            int x= total%k;
            if(i>=1 && x==0) return true;
            if(mp.find(x)!=mp.end()){
                if(i-mp[x]>1) return true;
            }
            else{
                mp[x]=i;
            }
        }
        return false;
    }
};