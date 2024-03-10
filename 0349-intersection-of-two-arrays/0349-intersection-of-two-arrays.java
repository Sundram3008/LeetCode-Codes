class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> st = new HashSet<>();
        for(int i=0; i<nums1.length; i++){
            st.add(nums1[i]);
        }
        HashSet<Integer> st1= new HashSet<>();
        for(int i=0; i<nums2.length; i++){
            if(st.contains(nums2[i])) st1.add(nums2[i]);
        }
        int[] res= new int[st1.size()];
        int i=0;
        for(Integer x: st1) res[i++]=x;
        return res;
    }
}