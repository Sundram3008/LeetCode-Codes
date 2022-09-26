class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxilen=0,maxAnd= *max_element(nums.begin(), nums.end()),ans=1;
        for(auto i: nums){
            if(i==maxAnd){
                maxilen+=1;
                ans=max(ans,maxilen);
            }else maxilen=0;
        }
        return ans;
    }
};