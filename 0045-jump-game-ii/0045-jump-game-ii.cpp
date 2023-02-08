class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int cnt=0, currReach=-1, maxReach=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(i>currReach){
                currReach= maxReach;
                cnt++;
            }
            maxReach= max(maxReach, i+nums[i]);
        }
        return cnt;
    }
};