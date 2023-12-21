class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });

        int ans = 0;
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] - points[i - 1][0] > ans) {
                ans = Math.max(ans, points[i][0] - points[i - 1][0]);
            }
        }

        return ans;
    }
}