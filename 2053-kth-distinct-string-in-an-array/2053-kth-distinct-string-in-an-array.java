class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String, Integer> freq= new HashMap<>();
        for(String i: arr) freq.put(i, freq.getOrDefault(i, 0)+1);
        for(String i: arr){
            if(freq.get(i)==1) k--;
            if(k==0) return i;
        }
        return "";
    }
}