class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n= nums.size(), idx=k;
        long long int sum=0;
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(i>= k*2){
                ans[idx++]= sum/(k*2 +1);
                sum-= nums[i-(k*2)];
            }
        }
        return ans;
    }
};