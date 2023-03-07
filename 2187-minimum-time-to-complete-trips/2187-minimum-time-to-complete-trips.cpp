#define ll long long
class Solution {
public:
    bool binarySearch(vector<int> &time, int k, ll mid){
        ll cnt=0;
        for(int i=0; i<time.size(); i++){
            cnt+= (mid/time[i]);
            if(cnt>=k) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low=1, high= (*min_element(time.begin(), time.end()))*1LL*totalTrips;
        while(low<high){
            ll mid= low+((high-low)/2);
            if(binarySearch(time, totalTrips, mid)){
                high= mid;
            }else low= mid+1;
        }
        return low;
    }
};