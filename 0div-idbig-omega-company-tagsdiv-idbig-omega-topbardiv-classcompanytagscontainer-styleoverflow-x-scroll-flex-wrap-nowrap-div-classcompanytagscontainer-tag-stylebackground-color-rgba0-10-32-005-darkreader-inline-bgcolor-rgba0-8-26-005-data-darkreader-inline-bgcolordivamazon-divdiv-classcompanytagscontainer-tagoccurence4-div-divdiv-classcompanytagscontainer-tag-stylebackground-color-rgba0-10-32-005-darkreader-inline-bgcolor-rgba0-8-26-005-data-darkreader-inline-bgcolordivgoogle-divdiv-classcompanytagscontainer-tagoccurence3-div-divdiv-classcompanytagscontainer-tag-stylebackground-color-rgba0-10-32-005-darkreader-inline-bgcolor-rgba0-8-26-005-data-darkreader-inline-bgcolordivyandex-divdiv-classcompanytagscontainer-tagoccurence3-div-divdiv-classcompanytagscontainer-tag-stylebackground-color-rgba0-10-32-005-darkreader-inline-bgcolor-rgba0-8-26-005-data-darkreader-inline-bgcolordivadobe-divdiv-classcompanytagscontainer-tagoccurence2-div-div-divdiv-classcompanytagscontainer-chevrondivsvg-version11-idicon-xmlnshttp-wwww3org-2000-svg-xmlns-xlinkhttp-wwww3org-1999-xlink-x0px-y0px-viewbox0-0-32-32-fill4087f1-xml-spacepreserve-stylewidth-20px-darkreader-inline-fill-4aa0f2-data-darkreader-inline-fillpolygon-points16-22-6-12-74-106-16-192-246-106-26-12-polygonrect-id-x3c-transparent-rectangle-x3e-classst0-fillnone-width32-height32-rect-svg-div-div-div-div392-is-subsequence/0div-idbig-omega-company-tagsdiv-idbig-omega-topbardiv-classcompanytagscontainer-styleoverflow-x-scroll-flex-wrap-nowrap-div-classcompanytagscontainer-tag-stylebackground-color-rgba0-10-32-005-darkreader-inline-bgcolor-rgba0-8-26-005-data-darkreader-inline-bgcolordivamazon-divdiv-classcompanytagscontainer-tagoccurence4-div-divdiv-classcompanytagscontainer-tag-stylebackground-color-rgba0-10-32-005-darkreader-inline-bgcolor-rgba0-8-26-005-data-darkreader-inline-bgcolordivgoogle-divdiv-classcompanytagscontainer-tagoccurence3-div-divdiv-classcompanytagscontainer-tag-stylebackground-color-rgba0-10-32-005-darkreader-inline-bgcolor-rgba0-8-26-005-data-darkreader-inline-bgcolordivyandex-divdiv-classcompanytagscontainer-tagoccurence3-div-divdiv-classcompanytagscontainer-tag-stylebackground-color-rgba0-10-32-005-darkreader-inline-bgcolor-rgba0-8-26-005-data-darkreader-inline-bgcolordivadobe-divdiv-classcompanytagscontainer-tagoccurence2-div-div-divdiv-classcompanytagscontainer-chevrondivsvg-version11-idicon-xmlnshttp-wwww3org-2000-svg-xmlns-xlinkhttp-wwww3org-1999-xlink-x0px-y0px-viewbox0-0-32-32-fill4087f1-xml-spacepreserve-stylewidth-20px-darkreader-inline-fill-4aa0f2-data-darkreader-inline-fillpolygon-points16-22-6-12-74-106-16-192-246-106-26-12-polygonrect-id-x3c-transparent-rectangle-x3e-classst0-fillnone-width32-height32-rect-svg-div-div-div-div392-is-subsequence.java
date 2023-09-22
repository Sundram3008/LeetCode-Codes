class Solution {
    public boolean isSubsequence(String s, String t) {
        int it1=0, it2=0;
        while(it1< s.length() && it2< t.length()){
            if(s.charAt(it1)==t.charAt(it2)){
                it1++;
            }
            it2++;
        }
        return (it1==s.length());
    }
}