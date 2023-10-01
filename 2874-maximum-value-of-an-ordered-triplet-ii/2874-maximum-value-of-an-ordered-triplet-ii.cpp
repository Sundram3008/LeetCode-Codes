class Solution {
public:
#define ll long long int
    long long maximumTripletValue(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size()-1; i++) mp[nums[i]]++;
        ll k= nums.back(), ans=0;
        for(int i=nums.size()-2; i>0; i--){
            mp[nums[i]]--;
            if(mp[nums[i]]<=0){
                mp.erase(nums[i]);
            }
            ll jth= (*(--mp.end())).first;
            ans = max(ans, (jth- nums[i]) * k);
            k= max(k, 1LL*nums[i]);
        } 
        return ans;
    }
    
};