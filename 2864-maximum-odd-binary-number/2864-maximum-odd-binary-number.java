class Solution {
    public String maximumOddBinaryNumber(String s) {
        int setBits=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='1') setBits++;
        }
        StringBuilder str= new StringBuilder(s);
        setBits-=1;
        str.setCharAt(s.length()-1, '1');
        int l=0;
        while(setBits>0){
            setBits--;
            str.setCharAt(l, '1');
            l++;
        }
        while(l<str.length()-1){
            str.setCharAt(l, '0');
            l++;
        }
        return str.toString();
    }
}