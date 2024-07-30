class Solution {
    public int minimumDeletions(String s) {
        int cntb=0, n=s.length(), res=n, cnt=0;
        int[] cnta= new int[n];
        for(int i=n-1; i>=0; i--){
            if(s.charAt(i)=='a') cnt++;
            cnta[i]=cnt;
        }
        for(int i=0; i<n; i++){
            if(s.charAt(i)=='b') cntb++;
            res= Math.min(res, cntb+cnta[i]);
        }
        return res-1;
    }
}