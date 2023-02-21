class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            int x = (mid%2==0)? mid+1: mid-1;
            if(nums[mid]==nums[x]) l= mid+1;
            else r= mid;
            //if(mid-1>=0 && mid+1<=nums.size()-1 && nums[mid]!= nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
        }
        return nums[l];
    }
};