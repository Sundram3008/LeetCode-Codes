class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0, prev= nums[0];
        for(int i=1; i<nums.size(); i++){
            if(prev>= nums[i]){
                cnt+= prev+1-nums[i];
                nums[i]= prev+1;
            }
            prev= nums[i];
        }
        return cnt;
    }
};