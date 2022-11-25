class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size(), mod= 1000000007;
        vector<int> l(n,-1), r(n,n);
        stack<int> st;
        long ans=0;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>= arr[i]) st.pop();
            if(!st.empty()) l[i]= st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]> arr[i]) st.pop();
            if(!st.empty()) r[i]= st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            ans+= long(abs(r[i]-i)*abs(i-l[i]))* arr[i];
            ans%=mod;
        }
        return ans;
    }
};