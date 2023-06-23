class Solution {
    
    private void helper(int idx, int n, String s, Map<String, Boolean> mp, List<String> temp, List<String> ans){
        if(idx==n){
            ans.add(String.join(" ", temp));
            return ;
        }
        String word="";
        for(int i=idx; i<n; i++){
            word+= s.charAt(i);
            if(mp.containsKey(word)){
                temp.add(word);
                helper(i+1, n, s, mp, temp, ans);
                temp.remove(temp.size()-1);
            }
        }
        
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> ans= new ArrayList<String>();
        List<String> temp= new ArrayList<String>();
        Map<String, Boolean> mp= new HashMap<String, Boolean>();
        for(String i: wordDict) mp.put(i, true);
        helper(0, s.length(), s, mp, temp, ans);
        return ans;
    }
}