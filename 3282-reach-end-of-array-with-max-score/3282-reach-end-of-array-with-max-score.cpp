class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n= nums.size();
        long long int res=0, l=0, i=1, currVal=nums[0];
        for(i=1; i<n; i++){
            if(currVal< nums[i]){
                res+= (i-l)*currVal;
                currVal= nums[i];
                l=i;
            }
        }
        res+= (i-l-1)*currVal;
        return res;
    }
};