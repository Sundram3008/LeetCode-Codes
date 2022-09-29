#define pp pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
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
//         int l=0,r=arr.size()-1;
//         while(r-l>=k){
//             if(abs(arr[l]-x)<=abs(arr[r]-x)) r--;
//             else l++;
//         }
//         vector<int> ans;
//         for(int i=l; i<=r; i++) ans.push_back(arr[i]);
//         return ans;
        
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};