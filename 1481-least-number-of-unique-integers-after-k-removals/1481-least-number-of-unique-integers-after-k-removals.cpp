class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i: arr) mp[i]++;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto i: mp){
            pq.push(i.second);
        }
        while(!pq.empty() && k>0){
            if(pq.top()<k){
                k-= pq.top();
                pq.pop();
            }else if(pq.top()==k){
                k=0;
                pq.pop();
            }else break;
        }
        return pq.size();
    }
};