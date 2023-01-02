class Solution {
    private void help(List<List<Integer>> ans, List<Integer> temp, int k, int n){
        if(temp.size()==k && n==0){
            List<Integer> li = new ArrayList<Integer>(temp);
            ans.add(li);
            return;
        }
        for(int i= (temp.size()==0)?1: temp.get(temp.size()-1)+1; i<=9; i++){
            if(n-i <0) break;
            temp.add(i);
            help(ans, temp, k, n-i);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans= new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        help(ans, temp, k, n);
        return ans;
    }
}