class Solution {
    public int numberOfSpecialChars(String word) {
        int []freq = new int[60];
        for(int i=0; i<word.length(); i++){
            freq[word.charAt(i)-'A']++;
        }
        int res=0;
        for(int i=0; i<26; i++){
            if(freq[i]>0 && freq[i+32]>0) res++;
        }
        return res;
    }
}