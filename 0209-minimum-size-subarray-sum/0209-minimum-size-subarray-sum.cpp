class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, ans= INT_MAX, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            while(sum>=target && l<=i){
                ans= min(i-l+1, ans);
                sum-= nums[l];
                l++;
            }
        }
        return (ans==INT_MAX)? 0: ans;
    }
};