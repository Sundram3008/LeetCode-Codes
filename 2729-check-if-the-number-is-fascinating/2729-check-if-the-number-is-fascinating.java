class Solution {
    boolean digs(int x, int []freq){
        while(x>0){
            int temp= x%10;
            x/=10;
            if(temp==0) return false;
            if(freq[temp-1]>0) return false;
            freq[temp-1]++;
        }
        return true;
    }
    public boolean isFascinating(int n) {
        int doubleval=2*n, tripleval=3*n;
        int []v = new int[9];
        boolean ones= digs(n, v), twos= digs(doubleval, v), threes= digs(tripleval, v);
        return ones && twos && threes;
    }
}