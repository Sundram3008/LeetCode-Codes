class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long sum=0, cnt=0;
        for(auto i: nums){
            sum+= i;
            if(sum>0) cnt++;
            else return cnt;
        }
        return cnt;
    }
};