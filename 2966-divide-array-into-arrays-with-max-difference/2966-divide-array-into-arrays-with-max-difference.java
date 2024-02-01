class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        
        int[][] res = new int[nums.length/3][3];
        int l=0;
        for(int i=0; i<nums.length; i+=3){
            int temp[]= new int[3];
            for(int j=i; j<= i+2; j++){
                if(nums[j]-nums[i]>k){ 
                    return new int[0][0];
                }
                temp[j-i]=nums[j];
            }
            res[l++]= temp;
        }
        return res;
    }
}