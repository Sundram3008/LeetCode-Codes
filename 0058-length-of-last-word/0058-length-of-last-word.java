class Solution {
    public int lengthOfLastWord(String s) {
        int ans=0, cnt=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)==' ') cnt=0;
            else cnt++;
            if(cnt>0)
            ans= cnt;
        }
        return ans;
    }
}