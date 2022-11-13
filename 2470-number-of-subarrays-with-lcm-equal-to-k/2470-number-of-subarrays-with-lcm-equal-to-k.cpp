
#define ll unsigned long long  int 
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            ll g= nums[i];
            for(int j=i; j<nums.size(); j++){
                g =  (nums[j] * g)/(__gcd((ll)nums[j], g));
                if(g==k) cnt++;
            }
        }
        return cnt;
    }
};