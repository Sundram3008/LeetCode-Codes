class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int val=0;
        for(int i=0; i<arr.length; i++){
            val = Math.min(val+1, arr[i]);
        }
        return val;
    }
}