class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;
        int i=1, sum=nums[0];
        while(i<nums.size()){
            if(nums[i-1]+1==nums[i]){
                sum+= nums[i];
            }else{
                break;
            }
            i++;
        }
        while(mp[sum]>0) sum++;
        return sum;
    }
};