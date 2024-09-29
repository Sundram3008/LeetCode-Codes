class Solution {
    public char kthCharacter(int k) {
        StringBuilder str= new StringBuilder();
        str.append("a");
        int l=0,x=1;
        while(k>str.length()){
            int val= (int)str.charAt(l)-'a';
            val= (val+1)%27;
            
            str.append((char)(val+'a'));
            l++;
            if(l==x){
                l=0;
                x= str.length();
            }
        }
       // System.out.println(str);
        return str.charAt(k-1);
    }
}