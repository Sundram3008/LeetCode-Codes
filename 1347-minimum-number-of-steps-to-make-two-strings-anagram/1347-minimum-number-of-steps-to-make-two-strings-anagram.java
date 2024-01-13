class Solution {
    public int minSteps(String s, String t) {
        int []freq = new int[26];
        for(int i=0; i<s.length(); i++){
            freq[s.charAt(i)-'a']++;
        }
        int cnt=0;
        for(int i=0; i<t.length(); i++){
            if(freq[t.charAt(i)-'a']<=0) cnt++;
            else freq[t.charAt(i)-'a']--;
        }
        return cnt;
    }
}