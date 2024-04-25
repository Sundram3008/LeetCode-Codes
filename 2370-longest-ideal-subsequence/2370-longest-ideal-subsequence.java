class Solution {
    public int longestIdealString(String s, int k) {
        int []dp = new int[26];
        int res=0;
        for(int i=0; i<s.length(); i++){
            int idx= s.charAt(i)- 'a';
            int maxWithChar=0;
            for(int j= Math.max(0, idx-k); j<=Math.min(25, idx+k); j++){
                maxWithChar= Math.max(maxWithChar, dp[j]);
            }
            dp[idx]= Math.max(dp[idx], maxWithChar+1);
            res = Math.max(res, dp[idx]);
        }
        return res;
    }
}