class Solution {
    public int minBitFlips(int start, int goal) {
        int cnt=0;
        
        while(start!=goal){
            if(start%2!= goal%2) cnt++;
            start/=2;
            goal/=2;
        }
        return cnt;
    }
}