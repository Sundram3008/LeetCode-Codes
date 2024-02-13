class Solution {
    public String firstPalindrome(String[] words) {
        
        for(int i=0; i<words.length; i++){
            int l=0, r= words[i].length()-1;
            boolean flag=true;
            while(l<r){
                if(words[i].charAt(l)!=words[i].charAt(r)){
                    flag=false;
                    break;
                }
                l++;
                r--;
            }
            if(flag) return words[i];
        }
        return "";
    }
}