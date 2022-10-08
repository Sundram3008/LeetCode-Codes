class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int f=0,s=1, t=nums.size()-1;
        long ans=nums[0]+nums[1]+nums[2];
        for(f=0; f<nums.size()-2; f++){
            s=f+1, t=nums.size()-1;
            while(s<t){
                int currSum= nums[f]+nums[s]+nums[t];
                if(abs(currSum-target)<abs(ans-target)){
                    ans=currSum;
                }
                if(currSum<target) s++;
                else t--;
            }
        }
        return ans;
    }
};