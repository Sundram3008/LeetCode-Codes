#define ll long long
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        ll curr=0, m=0;
        vector<ll> ans;
        for(int i=0; i<nums.size(); i++){
            m= max(m, (ll)nums[i]);
            curr+= nums[i]+m;
            ans.push_back(curr);
        }
        return ans;
    }
};