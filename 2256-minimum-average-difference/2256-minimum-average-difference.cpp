class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size()==1) return 0;
        long long int total=0;
        for(auto i: nums){
            total+= i;
        }
        long long int curr=0,idx=-1,mini=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
            long long int f=(nums.size()-i-1);
            if(f<=0) f=1;
            long long int diff= ((curr/(i+1))- ((total-curr)/f));
            diff= abs(diff);
            if(diff<mini){
                mini=diff;
                idx=i;
            }
        }
        return idx;
    }
};