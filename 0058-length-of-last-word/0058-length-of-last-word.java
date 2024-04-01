class Solution {
    public int lengthOfLastWord(String s) {
        // int ans=0, cnt=0;
        // for(int i=0; i<s.length(); i++){
        //     if(s.charAt(i)==' ') cnt=0;
        //     else cnt++;
        //     if(cnt>0)
        //     ans= cnt;
        // }
        int ans=0;
        for(int i=s.length()-1; i>=0; i--){
            if(s.charAt(i)!=' ') ans++;
            else{
                if(ans>0) return ans;
            }
        }
        return ans;
    }
}