class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini=INT_MAX, diff=INT_MAX;
        priority_queue<int> pq;
        for(auto i: nums){
            if(i%2==1) i*=2;
            pq.push(i);
            mini= min(mini,i);
        }
        while(pq.top()%2!=1){
            diff= min(diff, pq.top()-mini);
            mini= min(mini, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(diff, pq.top()-mini);
    }
};