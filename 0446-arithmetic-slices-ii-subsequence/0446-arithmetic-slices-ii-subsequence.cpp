class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long ans=0, n= nums.size();
        vector<unordered_map<long, long>> dp(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long diff= (long)((long)nums[i]- (long)nums[j]);
                dp[i][diff]++;
                if(dp[j][diff]>0){
                    dp[i][diff]+= dp[j][diff];
                    ans+= dp[j][diff];
                }
            }
        }
        return ans;
        
    }
};