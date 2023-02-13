class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int v1=0, v2=0, v3= INT_MAX, v4= INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(v1<nums[i]){
                v2=v1;
                v1=nums[i];
            }else if(nums[i]<=v1 && v2<nums[i]) v2= nums[i];
            
            if(v3> nums[i]){
                v4=v3;
                v3= nums[i];
            }else if(nums[i]>= v3 && v4>nums[i]) v4= nums[i];
        }
        return v2*v1 - v3*v4;
    }
};