class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2,0);
        for(auto i: nums){
            if(nums[abs(i)-1]<0) ans[0]=abs(i);
            else nums[abs(i)-1]*= -1;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0)  ans[1]=i+1;
        }
        return ans;
    }
};