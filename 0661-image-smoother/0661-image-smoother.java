class Solution {
    public int[][] imageSmoother(int[][] img) {
        int r= img.length, c= img[0].length;
        int [][] ans= new int[r][c];
        int []dir= {1, 0, -1};
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int cnt=0, val=0;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        int x= i+ dir[k], y= j+ dir[l];
                        if(x>=0 && x<r && y>=0 && y<c){
                            val+= img[x][y];
                            cnt++;
                        }
                    }
                }
                ans[i][j]= val/cnt;
            }
        }
        return ans;
    }
}