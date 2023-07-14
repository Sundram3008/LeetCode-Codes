class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> mp;
        int ans=1;
        for(auto &i: arr){
            int temp= i-diff;
            mp[i]= mp[temp]+1;
            ans= max(ans, mp[i]);
        }
        return ans;
    }
};