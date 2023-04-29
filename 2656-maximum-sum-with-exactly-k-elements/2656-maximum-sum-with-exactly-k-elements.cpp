class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int x= *max_element(nums.begin(), nums.end()), l= x+k-1;
        long ans=(l*(l+1)/2)-(x*(x-1)/2); 
        return ans;
    }
};