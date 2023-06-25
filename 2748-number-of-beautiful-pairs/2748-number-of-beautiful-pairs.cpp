class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int dig=0, x= nums[i];
            while(x>0){
                dig= x%10;
                x/=10;
            }
            for(int j=i+1;  j<nums.size(); j++){
                if(__gcd(dig,nums[j]%10)==1) ans++;
            }
        }
        return ans;
    }
};