class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long ,int> mp1, mp2;
        for(int i=0; i<nums2.size(); i++){
            for(int j=i+1; j<nums2.size(); j++) mp1[1LL* nums2[i]*nums2[j]]++;
        }
        for(int i=0; i<nums1.size(); i++){
            for(int j=i+1; j<nums1.size(); j++) mp2[1LL* nums1[i]*nums1[j]]++;
        }
        
        int ans=0;
        for(auto i: nums1){
            if(mp1.find(1LL*i*i)!=mp1.end()) ans+= mp1[1LL*i*i];
        }
        for(auto i: nums2){
            if(mp2.find(1LL*i*i)!=mp2.end()) ans+= mp2[1LL*i*i];
        }
        return ans;
    }
};