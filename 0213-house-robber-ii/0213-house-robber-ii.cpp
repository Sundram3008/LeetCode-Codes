class Solution {
public:
    int badHabit(int start, int end, vector<int> &nums){
        int took=0, leave=0;
        for(int i=start; i<= end; i++){
            int ntook= leave+ nums[i];
            int nleave= max(took, leave);
            took= ntook;
            leave= nleave;
        }
        return max(took, leave);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(badHabit(1, nums.size()-1, nums), badHabit(0, nums.size()-2, nums));
    }
};