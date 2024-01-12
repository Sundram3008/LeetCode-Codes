class Solution {
    public boolean isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A'|| ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    public boolean halvesAreAlike(String s) {
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s.charAt(i))){
                if(i< s.length()/2) cnt++;
                else cnt--;
            }
        }
        return cnt==0;
    }
}