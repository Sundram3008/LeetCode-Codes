class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size(), sum=0;
        int ans=0, cnt=0;
        queue<int> q;
        q.push(0);
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt++;
                q.push(sum);
            }
            else sum++;
            if(cnt<=k){
                ans= max(ans, sum-q.front()+cnt);
            }else{
                cnt--;
                q.pop();
            }
        }
        return ans;
    }
};