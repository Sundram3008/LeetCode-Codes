#define pp pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /* brute force O(nlogn)
        
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
        return ans;*/
        
        /* Little Optimized O(n)*/
        int l=0,r=arr.size()-1;
        while(r-l>=k){
            if(abs(arr[l]-x)<=abs(arr[r]-x)) r--;
            else l++;
        }
        vector<int> ans;
        for(int i=l; i<=r; i++) ans.push_back(arr[i]);
        return ans;
    }
};