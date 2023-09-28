class Solution {
    void freqFiller(int []a, String word){
        for(int i=0; i<word.length(); i++){
            a[word.charAt(i)-'a']++;
        }
        return;
    }
    public boolean isItPossible(String word1, String word2) {
        int fw1[] = new int[26], fw2[] = new int[26];
        freqFiller(fw1, word1);
        freqFiller(fw2, word2);
        int u1=0, u2=0;
        for(int i=0; i<26; i++){
            if(fw1[i]>0) u1++;
            if(fw2[i]>0) u2++;
        }
        for(int i=0; i<26; i++){
            if(fw1[i]>0){
                fw1[i]--;
                if(fw1[i]==0) u1--;
                for(int j=0; j<26; j++){
                    if(fw2[j]>0){
                        fw2[j]--;
                        if(fw2[j]==0) u2--;
                        fw1[j]++;
                        if(fw1[j]==1) u1++;
                        fw2[i]++;
                        if(fw2[i]==1) u2++;
                        if(u1==u2) return true;
                        fw2[j]++;
                        if(fw2[j]==1) u2++;
                        fw1[j]--;
                        if(fw1[j]==0) u1--;
                        fw2[i]--;
                        if(fw2[i]==0) u2--;
                    }
                }
                fw1[i]++;
                if(fw1[i]==1) u1++;
            }
        }
        return false;
    }
}