class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        multiset<int> st;
        for(auto i: nums1) st.insert(i);
        for(auto i: nums2){
            auto x= st.upper_bound(i);
            if(x==st.end())
                x=st.begin();
            ans.push_back(*x);
            st.erase(x);
        }
        return ans;
    }
};