class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i: nums1) mp.put(i, mp.getOrDefault(i, 0)+1);
        ArrayList<Integer> arr= new ArrayList<>();
        for(int j: nums2){
            if(mp.get(j)!= null && mp.get(j)>0){
                arr.add(j);
                mp.put(j, mp.get(j)-1);
            }
        }
        int []res = new int[arr.size()];
        for(int i=0; i<arr.size(); i++){
            res[i]= arr.get(i);
        }
        return res;
    }
}