class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums1.size(); i++) vp.push_back({nums2[i], nums1[i]});
        sort(vp.rbegin(), vp.rend());
        //priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        long long sum=0, ans=0;
        for(int i=0; i<k-1; i++){
            sum+= vp[i].second;
            pq.push(-vp[i].second);
        }
        for(int i=k-1; i<nums1.size(); i++){
            sum+= vp[i].second;
            pq.push(-vp[i].second);
            ans= max(ans, sum*vp[i].first);
            sum+= pq.top();
            pq.pop();
        }
        return ans;
    }
};