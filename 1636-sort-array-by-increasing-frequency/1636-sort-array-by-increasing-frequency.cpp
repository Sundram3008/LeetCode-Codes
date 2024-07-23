class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int *freq= new int[202];
        for(auto i: nums) freq[i+100]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
           if(freq[a+100]!=freq[b+100]) return freq[a+100]<freq[b+100];
            else return a>b;
        });
        return nums;
    }
};