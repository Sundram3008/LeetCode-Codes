#define pp pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto i: arr){
            pq.push({abs(i-x),i});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};