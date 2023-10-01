class Solution {
    public String reverseWords(String s) {
        String ans ="";
        s+= " ";
        int l=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)==' '){
                for(int j= i-1; j>=l; j--){
                    ans+= s.charAt(j);
                }
                l= i+1;
                ans+= " ";
            }
        }
        return ans.substring(0, s.length()-1);
    }
}