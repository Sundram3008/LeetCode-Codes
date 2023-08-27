class Solution {
public:
    bool helper(int idx, int k, int lastStone, unordered_map<int, bool> &stones, map<pair<int,int>, bool> &dp){
        if(idx==lastStone) return true;
        if(k<=0) return false;
        if(dp.find({idx, k})!= dp.end()) return dp[{idx, k}];
        if(stones[idx]==false) return false;
        bool pos= false;
        pos|= helper(idx+k, k-1, lastStone, stones, dp);
        pos|= helper(idx+k, k, lastStone, stones, dp);
        pos|= helper(idx+k, k+1, lastStone, stones, dp);
        dp[{idx, k}]=pos;
        return pos;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> mp;
        for(auto i: stones) mp[i]=true;
        map<pair<int,int>, bool> dp;
        return helper(0, 1, stones.back(), mp, dp);
    }
};