class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0, x=0;
        for(int i=0; i<nums.size(); i++){
            x^= nums[i];
        }
        while(x>0 || k>0){
            if(x%2!= k%2) ans++;
            x/=2;
            k/=2;
        }
        return ans;
    }
};