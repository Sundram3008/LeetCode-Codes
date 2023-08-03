class Solution {
    private void helper(int idx, String digs, StringBuffer temp, String[] pad, List<String> ans){
        if(idx== digs.length()){
            ans.add(temp.toString());
            return;
        }
        for(int i=0; i<pad[digs.charAt(idx)-'0' -2].length(); i++){
            temp.append(pad[digs.charAt(idx)-'0' -2].charAt(i));
            helper(idx+1, digs, temp, pad, ans);
            temp.deleteCharAt(temp.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<String>();
        if(digits.length()==0) return ans;
        StringBuffer temp = new StringBuffer();
        String []pad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        helper(0, digits, temp, pad, ans);
        
        return ans;
    }
}