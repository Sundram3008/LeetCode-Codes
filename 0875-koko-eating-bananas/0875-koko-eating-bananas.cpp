class Solution {
public:
    bool binarySearch(vector<int>& p, long long mid, int h){
        int cnt=0;
        for(auto i: p){
            cnt+= ceil(i*1.0/mid);
            if(cnt>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high= accumulate(piles.begin(), piles.end(), 0LL);
        while(low<high){
            long long mid= low+ ((high-low)/2);
            if(binarySearch(piles, mid, h)) high=mid;
            else low= mid+1;
        }
        return low;
    }
};