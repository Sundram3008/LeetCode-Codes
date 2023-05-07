class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> st;
        int n= nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            unordered_set<int> x;
            for(int j=i+1; j<n; j++){
                x.insert(nums[j]);
            }
            ans[i]= st.size()-x.size();
        }
        return ans;
    }
};