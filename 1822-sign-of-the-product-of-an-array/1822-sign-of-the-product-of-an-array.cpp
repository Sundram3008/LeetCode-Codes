class Solution {
public:
    int signFunc(int pro){
        if(pro%2) return -1;
        return 1;
    }
    int arraySign(vector<int>& nums) {
        int z=0, neg=0;
        for(auto &i: nums){
            if(i==0)  return 0;
            if(i<0) neg++;
        }
        return signFunc(neg);
    }
};