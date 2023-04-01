class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int a= *min_element(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_map<int,int> mp;
        for(auto i: nums1) mp[i]++;
        for(auto i: nums2) {
            if(mp.find(i)!=mp.end()) return i;
        }
        if(a<nums2[0]) return (a*10 +nums2[0]);
        else return (nums2[0]*10+a);
    }
};