class Solution {
public:
    int xorCalc(vector<int> v){
        int ans=0;
        for(auto i: v){
            ans^=i;
        }
        return ans;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        if(n%2==0 && m%2==0) return 0;
        else if(n%2==0 && m%2) return xorCalc(nums1);
        else if(n%2 && m%2==0) return xorCalc(nums2);
        else return xorCalc(nums1)^xorCalc(nums2);
    }
};