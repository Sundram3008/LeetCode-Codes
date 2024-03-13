class Solution {
    public int pivotInteger(int n) {
        for(int i=1; i<=n; i++){
            int val = i*(i+1)/2;
            if(val == ((n*(n+1)/2)-val+i)) return i;
        }
        return -1;
    }
}