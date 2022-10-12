class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int val1= min(abs(nums[0]-nums[n-4]), abs(nums[3]-nums[n-1]));
        int val2= min(abs(nums[1]-nums[n-3]),abs(nums[2]-nums[n-2]));
        return min(val1,val2);
    }
};