class Solution {
public:
    bool isPossible(vector<int> &v, int days, int val){
        int cnt=1, curr=0;
        for(auto i: v){
            curr+= i;
            if(i>val) return false;
            if(curr>val){
                curr=i;
                cnt++;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r= accumulate(weights.begin(), weights.end(),0), l=0, ans= r;
        while(l<r){
            int mid= l+(r-l)/2;
            if(isPossible(weights, days, mid)){
                r= mid;
                ans= mid;
            }else l=mid+1;
        }
        return ans;
    }
};