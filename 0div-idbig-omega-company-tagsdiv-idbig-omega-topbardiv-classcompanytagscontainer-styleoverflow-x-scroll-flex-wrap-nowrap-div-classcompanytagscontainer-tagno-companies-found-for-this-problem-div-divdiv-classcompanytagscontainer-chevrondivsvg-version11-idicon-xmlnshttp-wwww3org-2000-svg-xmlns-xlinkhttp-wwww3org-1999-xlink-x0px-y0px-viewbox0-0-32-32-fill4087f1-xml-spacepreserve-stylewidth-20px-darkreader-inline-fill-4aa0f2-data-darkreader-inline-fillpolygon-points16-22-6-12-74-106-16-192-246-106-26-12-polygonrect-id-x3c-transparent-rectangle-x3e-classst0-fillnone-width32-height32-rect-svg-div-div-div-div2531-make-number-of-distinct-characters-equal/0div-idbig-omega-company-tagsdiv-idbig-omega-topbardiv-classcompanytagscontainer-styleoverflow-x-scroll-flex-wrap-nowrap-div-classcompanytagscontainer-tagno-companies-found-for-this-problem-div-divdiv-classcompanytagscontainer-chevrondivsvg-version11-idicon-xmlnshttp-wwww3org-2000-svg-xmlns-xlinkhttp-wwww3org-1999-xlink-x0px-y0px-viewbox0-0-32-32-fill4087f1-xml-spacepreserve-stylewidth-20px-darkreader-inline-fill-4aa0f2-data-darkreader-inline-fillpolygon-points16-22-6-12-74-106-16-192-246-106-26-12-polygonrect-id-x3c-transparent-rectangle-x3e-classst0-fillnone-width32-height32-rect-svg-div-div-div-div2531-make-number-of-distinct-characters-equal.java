class Solution {
    void freqFiller(int []a, String word){
        for(int i=0; i<word.length(); i++){
            a[word.charAt(i)-'a']++;
        }
        return;
    }
    boolean valid(int []a, int[]b){
        int u1=0, u2=0;
        for(int i=0; i<26; i++){
            if(a[i]>0) u1++;
            if(b[i]>0) u2++;
        }
        return (u1==u2);
    }
    public boolean isItPossible(String word1, String word2) {
        int fw1[] = new int[26], fw2[] = new int[26];
        freqFiller(fw1, word1);
        freqFiller(fw2, word2);
        for(int i=0; i<26; i++){
            if(fw1[i]>0){
                fw1[i]--;
                for(int j=0; j<26; j++){
                    if(fw2[j]>0){
                        fw2[j]--;
                        fw1[j]++;
                        fw2[i]++;
                        if(valid(fw1, fw2)) return true;
                        fw2[j]++;
                        fw1[j]--;
                        fw2[i]--;
                    }
                }
                fw1[i]++;
            }
        }
        return false;
    }
}