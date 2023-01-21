#define ll long long int
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        ll neg=0, pos=0;
        for(int i=0; i< nums1.size(); i++){
            ll val= nums1[i]-nums2[i];
            if(val<0) neg+= abs(val);
            else pos+= val;
        }
        if(neg==pos && k==0) return (neg==0)?0:-1;
        else if(neg!=pos || (k==0 && neg>0) || pos%k!=0) return -1;
        else return neg/k;
    }
};