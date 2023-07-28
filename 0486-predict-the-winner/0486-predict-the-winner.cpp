class Solution {
public:
    // void predicts(vector<int> &nums, int idx, int p1, int p2, int chance, int &diff, bool &ans){
    //     if(idx>=nums.size()){
    //         if(diff >= abs(p1-p2)){
    //             cout<<p1<<" : "<<p2<<endl;
    //             if(diff== abs(p1-p2)){
    //                 if(p1>=p2 || ans){
    //                     ans=true;
    //                 }
    //             }else{
    //                 diff=abs(p1-p2);
    //                 if(p1>=p2){ 
    //                     //cout<<p1<<" "<<p2<<endl;
    //                     ans=true;
    //                 }else ans=false;
    //             }
    //         }
    //         return ;
    //     }
    //     predicts(nums, idx+1, (chance)? p1 + nums[idx]: p1, (chance==0)?p2+ nums[idx] : p2, 1-chance, diff, ans);
    //     int x= nums.back();
    //     nums.pop_back();
    //     predicts(nums, idx, (chance)? p1 + x: p1, (chance==0)?p2+ x : p2, 1-chance, diff, ans);
    //     nums.push_back(x);
    //     return ;
    // }
    int predicts(vector<int> &nums, int l, int r, vector<vector<int>> &dp){
        if(l>r) return 0;
        if(l==r) return nums[l];
        if(dp[l][r]!= -1) return dp[l][r];
        int curr= max(nums[l] + min(predicts(nums, l+2, r, dp), predicts(nums, l+1, r-1, dp)), nums[r]+ min(predicts(nums, l, r-2, dp), predicts(nums, l+1, r-1, dp)));
        dp[l][r]=curr;
        return curr;
    }
    bool PredictTheWinner(vector<int>& nums) {
        // int diff=INT_MAX;
        // bool ans= false;
        // predicts(nums, 0, 0, 0, 1, diff, ans);
        // return ans;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int person1= predicts(nums, 0, nums.size()-1, dp);
        return (person1>=total-person1);
    }
};