class Solution {
    public int maxScore(String s) {
        int totalo=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)== '1') totalo++;
        }
        int currz=0, ans=0;
        for(int i=0; i<s.length()-1; i++){
            if(s.charAt(i)=='1') totalo--;
            else currz++;
            ans= Math.max(ans, totalo+currz);
        }
        return ans;
    }
}