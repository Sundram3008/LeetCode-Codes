class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int v1=0, v2=0;
        for(int i=0; i<nums.size(); i++){
            if(v1<=nums[i]){
                v2=v1;
                v1= nums[i];
            }
            else if(nums[i]<=v1 && v2<nums[i]) v2= nums[i];
        }
        v1--, v2--;
        return v1*v2;
    }
};