class Solution {
    public boolean judgeSquareSum(int c) {
        
        int maxi= (int)Math.pow(Integer.MAX_VALUE, 0.5);
        for(int i=0; i<=maxi; i++){
            int got= c- (i*i);
            got= (int)Math.pow(got, 0.5);
            if(i*i + (got*got) == c && got*got == c-(i*i)) return true;
        }
        return false;
    }
}