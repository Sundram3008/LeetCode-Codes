class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=0;
        for(int i=0; i<arr.size(); i++){
            int x= arr[i]-prev-1;
            if(x>0){
                if(x>=k) return prev+k;
                k-=x;
            }
            prev=arr[i];
        }
        return prev+k;
    }
};