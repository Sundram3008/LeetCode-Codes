class Solution {
    public String getHint(String secret, String guess) {
        int smp[]= new int[10], gmp[]= new int[10];
        int bull=0, cow=0, n= secret.length();
        for(int i=0; i<n; i++){
            char a= secret.charAt(i), b= guess.charAt(i);
            if(a==b) bull++;
            else {
                smp[a-'0']++;
                gmp[b-'0']++;
            }
        }
        for(int i=0; i<10; i++){
            cow+= Math.min(smp[i], gmp[i]);
        }
        return Integer.toString(bull)+ "A"+ Integer.toString(cow)+ "B";
    }
}