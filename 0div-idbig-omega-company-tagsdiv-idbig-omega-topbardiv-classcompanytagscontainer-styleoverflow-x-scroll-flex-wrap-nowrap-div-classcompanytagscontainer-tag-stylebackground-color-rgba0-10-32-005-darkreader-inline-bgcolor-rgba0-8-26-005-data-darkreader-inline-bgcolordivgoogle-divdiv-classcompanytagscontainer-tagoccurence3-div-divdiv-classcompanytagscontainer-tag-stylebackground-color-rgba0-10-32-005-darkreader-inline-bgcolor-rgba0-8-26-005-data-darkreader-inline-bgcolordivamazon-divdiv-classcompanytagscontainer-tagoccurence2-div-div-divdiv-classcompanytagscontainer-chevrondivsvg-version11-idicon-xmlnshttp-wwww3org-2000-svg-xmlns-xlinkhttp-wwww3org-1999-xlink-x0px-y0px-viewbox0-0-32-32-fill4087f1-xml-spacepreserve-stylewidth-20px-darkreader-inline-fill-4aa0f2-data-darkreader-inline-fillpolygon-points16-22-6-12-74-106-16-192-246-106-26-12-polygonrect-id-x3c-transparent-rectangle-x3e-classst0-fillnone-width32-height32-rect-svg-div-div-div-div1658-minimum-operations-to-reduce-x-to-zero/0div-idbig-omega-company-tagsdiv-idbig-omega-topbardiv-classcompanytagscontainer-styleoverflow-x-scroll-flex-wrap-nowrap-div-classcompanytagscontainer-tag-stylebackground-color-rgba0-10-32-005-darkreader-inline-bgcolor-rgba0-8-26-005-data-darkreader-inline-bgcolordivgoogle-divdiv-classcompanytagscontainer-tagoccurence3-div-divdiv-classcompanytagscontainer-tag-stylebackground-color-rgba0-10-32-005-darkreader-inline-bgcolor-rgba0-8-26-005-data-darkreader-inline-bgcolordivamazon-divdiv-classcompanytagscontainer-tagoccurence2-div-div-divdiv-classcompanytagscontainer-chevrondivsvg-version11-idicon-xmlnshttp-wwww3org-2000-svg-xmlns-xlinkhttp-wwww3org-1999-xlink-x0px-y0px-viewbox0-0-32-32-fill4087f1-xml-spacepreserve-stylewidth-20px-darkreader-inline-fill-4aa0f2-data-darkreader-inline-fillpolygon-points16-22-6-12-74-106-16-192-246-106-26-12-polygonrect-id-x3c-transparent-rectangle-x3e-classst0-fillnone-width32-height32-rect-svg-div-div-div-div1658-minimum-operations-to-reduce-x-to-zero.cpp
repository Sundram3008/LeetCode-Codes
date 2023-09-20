class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=accumulate(nums.begin(),nums.end(),0),sum=total-x,maxlen=0,currsum=0,i=0;
        if(sum==0) return nums.size();
        for(int j=0; j<nums.size(); j++){
            currsum+= nums[j];
            while(i<nums.size() && currsum>sum) currsum-= nums[i++];
            if(currsum == sum) maxlen= max(maxlen, j-i+1);
        }
        if(!maxlen) return -1;
        return nums.size()-maxlen;
    }
};