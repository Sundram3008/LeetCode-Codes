class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        Set<Integer> mp = new HashSet<>();
        Set<Integer> mp1 = new HashSet<>();
        for(int i=0; i<nums1.length; i++){
            mp.add(nums1[i]);
        }
        for(int i=0; i<nums2.length; i++){
            mp1.add(nums2[i]);
        }
        int []ans={0,0};
        for(int i=0; i<nums1.length; i++){
            if(mp1.contains(nums1[i])) ans[0]++;
        }
        for(int i=0; i<nums2.length; i++){
            if(mp.contains(nums2[i])) ans[1]++;
        }
        return ans;
    }
}