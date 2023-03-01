class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r){
        int arr[m-l+1], arr1[r-m];
        for(int i=0; i< m-l+1; i++) arr[i]= nums[l+i];
        for(int i=0; i<r-m; i++) arr1[i]= nums[m+1+i];
        int i=0, j=0, k=l;
        while(i< m-l+1 && j<r-m){
            if(arr[i]<=arr1[j]) nums[k]= arr[i++];
            else nums[k]= arr1[j++];
            k++;
        }
        while(i< m-l+1 ) nums[k++]= arr[i++];
        while(j< r-m) nums[k++]= arr1[j++];
        return ;
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l<r){
            int m= l+(r-l)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);
            
            merge(nums, l, m, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};