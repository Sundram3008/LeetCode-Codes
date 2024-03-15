class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        long prefix=1;
        for(int i=0; i<nums.size(); i++){
            ans[i]*= prefix;
            prefix*=nums[i];
        }
        prefix=1;
        for(int i=nums.size()-1; i>=0; i--){
            ans[i]*= prefix;
            prefix*= nums[i];
        }
        return ans;
    }
};