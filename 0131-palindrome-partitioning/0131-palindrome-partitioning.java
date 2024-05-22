class Solution {
    boolean isPal(String x){
        int l=0, r= x.length()-1;
        while(l<r){
            if(x.charAt(l)!= x.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
    List<List<String>> res;
    void helper(String s, int idx, List<String> temp){
        if(idx>=s.length()){
            res.add(new ArrayList<>(temp));
            return;
        }
        String x="";
        for(int i=idx; i<s.length(); i++){
            x+=s.charAt(i);
            if(isPal(x)){
                temp.add(x);
                helper(s, i+1, temp);
                temp.remove(temp.size()-1);
            }
        }
        return ;
    }
    public List<List<String>> partition(String s) {
        res= new ArrayList<>();
        List<String> temp= new ArrayList<String>();
        helper(s, 0, temp);
        return res;
    }
}