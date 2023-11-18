class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int res=1;
        int pos=nums.length-1, curr=k, sum=0;
        for(int i=nums.length-1; i>=0 && pos>0; i--){
            if(i!= nums.length-1) curr+= ((i+1-pos)*nums[i+1] - sum-nums[i])-(((i-pos)*nums[i])- sum);
            while(pos-1>=0 && nums[i]-nums[pos-1]<= curr){
                sum+= nums[--pos];
                curr-= (nums[i]-nums[pos]);
            }
            res= Math.max(res,i-pos+1);
            sum-= nums[i];
        }
        return res;
    }
}