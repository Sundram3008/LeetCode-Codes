class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int lastPoint = points[0][1], ans=0;
        for(int i=1; i<points.length; i++){
            if(lastPoint < points[i][0]){
                ans++;
                lastPoint= points[i][1];
            }
        }
        return ans+1;
    }
}