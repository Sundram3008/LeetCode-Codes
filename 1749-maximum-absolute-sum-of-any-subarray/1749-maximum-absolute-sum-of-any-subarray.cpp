class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr1=0, curr2=0, sum1=0, sum2=0;
        for(int i=0; i<nums.size(); i++){
            curr1+= nums[i];
            curr2 += (-1* nums[i]);
            if(curr1>sum1) sum1=curr1;
            if(curr1<=0) curr1=0;
            if(curr2>sum2) sum2= curr2;
            if(curr2<=0) curr2=0;
        }
        return max(sum1, sum2);
    }
};