class Solution {
public:
    // bool check(int t, vector<int> &x){
    //     if(x[0]%2!=0 || x[0]>t) return false;
    //     for(int i=1; i<x.size(); i++){
    //         if(((x[i]%2)==(x[i-1]%2)) || x[i]>t) return false;
    //     }
    //     return true;
    // }
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
//         int ans=0;
//         for(int i=0; i<nums.size(); i++){
//             vector<int> temp;
//             for(int j=i; j<nums.size(); j++){
//                 temp.push_back(nums[j]);
                
//                 if(check(threshold, temp)){
//                     ans= max(ans, (int)temp.size());
//                 }
//             }
//         }
//         return ans;
        int ans=0, cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                if(nums[i]%2==0 && nums[i]<= threshold){
                    cnt++;
                }
                ans= max(ans, cnt);
                continue;
            }
            if(nums[i]%2!=nums[i-1]%2 && nums[i]<= threshold){
                cnt++;
            }else {
                cnt= (nums[i]%2==0 && nums[i]<=threshold);
            }
            ans= max(ans, cnt);
        }
        return ans;
    }
};