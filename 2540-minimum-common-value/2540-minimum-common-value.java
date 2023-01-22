class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int f=0, s=0;
        while(f<nums1.length && s<nums2.length){
            if(nums1[f]<nums2[s]) f++;
            else if(nums1[f]> nums2[s]) s++;
            else return nums1[f];
        }
        return -1;
    }
}