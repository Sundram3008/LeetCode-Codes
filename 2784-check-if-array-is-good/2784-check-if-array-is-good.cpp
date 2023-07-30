class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()<2) return false;
        sort(nums.begin(), nums.end());
        int cnt=0;
        for(int i=0; i<=nums.size()-2; i++){
            cnt+=1;
            if(nums[i]!=cnt) return false;
        }
        if(nums.back()!= cnt) return false;
        return true;
    }
};