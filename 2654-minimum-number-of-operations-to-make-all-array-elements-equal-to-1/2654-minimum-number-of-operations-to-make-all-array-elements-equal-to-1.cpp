class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones=0;
        for(auto &i: nums){
            if(i==1) ones++;
        }
        if(ones!=0) return nums.size()-ones;
        int ml=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int x= nums[i];
            for(int j=i+1; j<nums.size(); j++){
                x= __gcd(x, nums[j]);
                if(x==1){
                    ml = min(ml, j-i);
                    break;
                }
            }
        }
        if(ml!=INT_MAX){
            return ml+ nums.size()-1;
        }else return -1;
    }
};