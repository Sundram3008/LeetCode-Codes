class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> res= new ArrayList<>();
        int idx=0;
        for(int val=1; val<=n && idx<target.length; val++){
            res.add("Push");
            if(target[idx]!= val){
                res.add("Pop");
            }else idx++;
        }
        return res;
    }
}