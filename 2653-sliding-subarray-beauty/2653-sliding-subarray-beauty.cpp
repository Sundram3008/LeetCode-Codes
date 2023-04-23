class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> freq(51, 0);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>=k)
                if(nums[i-k]<0) freq[nums[i-k]+50]--;
            
            if(nums[i]<0) freq[nums[i]+50]++;
            
            if(i>=k-1){
                int cnt=0, l=0;
                for(int j=0; j<50; j++){
                    cnt+= freq[j];
                    if(cnt>=x){
                        l= j-50;
                        break;
                    }
                }
                ans.push_back(l);
            }
        }
        return ans;
    }
};