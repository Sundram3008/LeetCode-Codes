class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r= nums.size()-1;
        while(l<r){
            int mid= l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l= mid+1;
            }
            else r=mid;
        }
        return (nums[l]<target)?l+1:l;
    }
};