class Solution {
    private int encrypt(int num){
        int res = num;
        int largest=0;
        while(res>0){
            largest = Math.max(largest, res%10);
            res/=10;
        }
        while(num>0){
            res= (res*10)+ largest;
            num/=10;
        }
        return res;
    }
    public int sumOfEncryptedInt(int[] nums) {
        int sum=0;
        for(int i: nums){
            sum+= encrypt(i);
        }
        return sum;
    }
}