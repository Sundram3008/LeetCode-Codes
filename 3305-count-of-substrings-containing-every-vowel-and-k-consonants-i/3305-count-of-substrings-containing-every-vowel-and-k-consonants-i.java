class Solution {
    public int countOfSubstrings(String word, int k) {
        int res=0;
        for(int i=0; i<word.length(); i++){
            int a=0, e=0, eye=0, o=0, u=0, conscnt=0;
            for(int j=i; j<word.length(); j++){
                Character ch= word.charAt(j);
                if(ch=='a') a++;
                else if(ch=='e') e++;
                else if(ch=='i') eye++;
                else if(ch=='o') o++;
                else if(ch=='u') u++;
                else conscnt++;
                if(a>0 && e>0 && eye>0 && o>0 && u>0 && conscnt==k) res++;
            }
        }
        return res;
    }
    
}