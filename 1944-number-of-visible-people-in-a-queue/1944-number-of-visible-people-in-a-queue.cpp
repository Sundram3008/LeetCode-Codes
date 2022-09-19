class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n,0);
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            int cnt=0;
            while(!st.empty() && heights[st.top()]<heights[i]){ 
                st.pop();
                cnt++;
            }
            ans[i]=cnt + (st.size()>0);
            st.push(i);
        }
        return ans;
    }
};