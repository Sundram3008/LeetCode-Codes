class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String a="", b="";
        for(String i: word1) a+= i;
        for(String i: word2) b+= i;
        return a.equals(b);
    }
}