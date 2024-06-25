class Solution {
    public String maxValue(String n, int x) {
        StringBuffer res= new StringBuffer(n);
        int l=0;
        if(n.charAt(0)=='-'){
            l=1;
            while(l<n.length() && res.charAt(l)-'0'<= x) l++;
            if(l==n.length()) res.append((char)(x+'0'));
            else res.insert(l, (char)(x+'0'));
        }else{
            
            while(l<n.length() && res.charAt(l)-'0'>= x) l++;
            if(l==n.length()) res.append((char)(x+'0'));
            else res.insert(l, (char)(x+'0'));
        }
        return res.toString();
    }
}