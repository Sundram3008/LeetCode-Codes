class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0, ans=0, curr=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                l=curr+1;
                curr=i;
            }
            ans= max(ans, i-l);
        }
        return ans;
    }
};