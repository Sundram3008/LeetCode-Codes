class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // brute
        
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]>arr[i-1] && arr[i+1]<arr[i]) return i;
        }
        return -1;
    }
};