class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r= matrix.length, c= matrix[0].length;
        int i=r-1, j=0;
        while(i>=0 && j<c){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }
}