class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()<2) return {to_string(nums[0])};
        vector<string> ans;
        long n=nums.size(), cnt=0, x= nums[0], y= nums[0]; 
        for(int i=0; i<n; i++){
            if(x==nums[i]){
                x++;
                cnt++;
            }else{
                if(cnt>1){
                    ans.push_back(to_string(y)+"->"+ to_string(x-1));
                }else{
                    ans.push_back(to_string(y));
                }
                x=(long)nums[i]+1;
                y=nums[i];
                cnt=1;
            }
        }
        if(cnt>1){
            ans.push_back(to_string(y)+"->"+ to_string(x-1));
        }else{
            ans.push_back(to_string(y));
        }
        return ans;
    }
};