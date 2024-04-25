class Solution {
    public int numberOfSpecialChars(String word) {
        int[] freq = new int[60];
        for(int i=0; i<word.length(); i++){
            int ascii= word.charAt(i);
            freq[ascii-65]++;
            if(ascii>=97 && freq[ascii-97]>0) freq[ascii-65]=0; 
        }
        int res=0;
        for(int i=0; i<26; i++){
            if(freq[i]>0 && freq[i+32]>0) res++;
        }
        return res;
    }
}