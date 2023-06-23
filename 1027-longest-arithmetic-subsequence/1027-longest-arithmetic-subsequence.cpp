class Solution {
public:
    // int findLength(vector<int> &nums, int diff){
    //     int ans=0;
    //     unordered_map<int,int> mp;
    //     for(int i=0; i<nums.size(); i++){
    //         mp[nums[i]]=mp[nums[i]-diff]+1;
    //         ans= max(mp[nums[i]], ans);
    //     }
    //     return ans;
    // }
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size(), ans=2;
        vector<unordered_map<int,int>> dp(n);
        for(int i=0; i<n; i++){
            for(int j= 0; j<i; j++){
                int diff= nums[i]-nums[j];
                int cnt = 1;
                if(dp[j].count(diff)) cnt = dp[j][diff];
                dp[i][diff] = 1 + cnt;  
                ans= max(dp[i][diff], ans);
            }
        }
        return ans;
    }
};