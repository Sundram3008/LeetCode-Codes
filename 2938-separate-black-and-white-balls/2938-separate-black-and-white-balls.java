class Solution {
    public long minimumSteps(String s) {
        int i=s.length()-1, j=s.length()-1;
        long ans=0;
        while(i>=0){
            if(s.charAt(i)=='1'){
                ans+= (j-i);
                j--;
            }
            i--;
        }
        return ans;
    }
}