class Solution {
    public int findComplement(int num) {
        int res=0, idx=0;
        while(num>0){
            res+= ((1-(num%2))* Math.pow(2, idx++));
            num/=2;
        }
        return res;
    }
}