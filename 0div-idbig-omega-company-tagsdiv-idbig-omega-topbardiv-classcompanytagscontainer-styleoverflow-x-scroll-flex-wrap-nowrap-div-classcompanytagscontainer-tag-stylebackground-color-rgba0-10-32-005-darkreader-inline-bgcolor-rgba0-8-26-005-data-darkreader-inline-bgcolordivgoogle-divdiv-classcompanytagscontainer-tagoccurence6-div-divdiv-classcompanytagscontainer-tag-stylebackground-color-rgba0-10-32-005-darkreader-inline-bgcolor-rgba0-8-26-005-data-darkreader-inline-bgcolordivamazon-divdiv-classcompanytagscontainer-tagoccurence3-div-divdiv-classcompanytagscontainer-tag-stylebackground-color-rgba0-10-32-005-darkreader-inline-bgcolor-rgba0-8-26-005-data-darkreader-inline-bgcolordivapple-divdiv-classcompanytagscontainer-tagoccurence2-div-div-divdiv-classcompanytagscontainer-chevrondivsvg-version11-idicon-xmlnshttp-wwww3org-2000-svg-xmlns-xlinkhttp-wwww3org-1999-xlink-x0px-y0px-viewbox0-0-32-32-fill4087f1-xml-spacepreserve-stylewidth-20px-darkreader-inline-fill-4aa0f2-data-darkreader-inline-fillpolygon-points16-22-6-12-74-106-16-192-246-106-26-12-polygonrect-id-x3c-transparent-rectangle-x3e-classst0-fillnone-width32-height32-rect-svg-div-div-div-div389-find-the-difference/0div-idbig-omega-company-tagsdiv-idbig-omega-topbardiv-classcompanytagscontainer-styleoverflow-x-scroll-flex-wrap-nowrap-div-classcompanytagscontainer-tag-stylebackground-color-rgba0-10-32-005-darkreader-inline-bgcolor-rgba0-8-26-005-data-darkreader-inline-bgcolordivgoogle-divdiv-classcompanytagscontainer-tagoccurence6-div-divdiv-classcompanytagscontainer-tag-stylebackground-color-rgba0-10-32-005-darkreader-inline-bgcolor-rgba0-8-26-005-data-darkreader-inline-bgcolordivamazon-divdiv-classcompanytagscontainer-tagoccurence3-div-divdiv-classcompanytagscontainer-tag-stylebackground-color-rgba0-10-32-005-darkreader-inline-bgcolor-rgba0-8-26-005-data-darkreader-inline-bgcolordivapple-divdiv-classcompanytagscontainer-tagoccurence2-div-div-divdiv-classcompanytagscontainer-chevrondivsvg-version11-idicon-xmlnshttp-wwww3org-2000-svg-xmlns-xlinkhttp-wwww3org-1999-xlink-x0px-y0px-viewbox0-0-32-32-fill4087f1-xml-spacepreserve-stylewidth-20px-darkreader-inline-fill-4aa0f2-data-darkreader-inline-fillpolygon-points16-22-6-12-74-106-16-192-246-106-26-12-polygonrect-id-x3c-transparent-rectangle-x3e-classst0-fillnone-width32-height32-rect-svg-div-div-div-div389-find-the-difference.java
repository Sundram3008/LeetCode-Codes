class Solution {
    public char findTheDifference(String s, String t) {
        int res=0, idx=0;
        while(idx<t.length()){
            if(idx< s.length()) res^= s.charAt(idx);
            res^= t.charAt(idx);
            idx++;
        }
        return (char)res;
    }
}