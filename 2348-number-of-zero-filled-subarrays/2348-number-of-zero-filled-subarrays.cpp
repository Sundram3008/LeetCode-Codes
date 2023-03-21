class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // long long zcnt=0, ans=0;
        // for(int i=0; i<nums.size()-1; i++){
        //     if(zcnt==0 && nums[i]==0) zcnt=1;
        //     if(nums[i]==0 && nums[i+1]==0){
        //         zcnt++;
        //     }
        //     else{
        //         ans+=  ((zcnt *1LL * (zcnt+1))/2);
        //         zcnt=0;
        //     }
        // }
        // if(zcnt==0 && nums.back()==0) ans++;
        // if(zcnt!=0){
        //     ans+=  ((zcnt *1LL * (zcnt+1))/2);
        // }
        // return ans;
        long long ans=0, l=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]!=0) l=r+1;
            ans+= (r-l +1);
        }
        return ans;
    }
};