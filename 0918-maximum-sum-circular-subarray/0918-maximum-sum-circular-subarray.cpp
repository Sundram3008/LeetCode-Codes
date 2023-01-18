class Solution {
public:
    int maxSubarray(vector<int> &nums){
        int res=INT_MIN, curr=0;
        for(int i=0; i<nums.size(); i++){
            curr+= nums[i];
            res= max(res, curr);
            if(curr<=0) curr=0;
        }
        return res;
        
    }
    int  minSubarray(vector<int> &nums){
        int res= INT_MAX, curr=0;
        for(int i=0; i<nums.size(); i++){
            curr+= nums[i];
            res= min(res, curr);
            if(curr>=0 ) curr=0;
        }
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_val= maxSubarray(nums), min_val= minSubarray(nums);
        int sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum==min_val) return max_val;
        return max(max_val, sum-min_val);
    }
};