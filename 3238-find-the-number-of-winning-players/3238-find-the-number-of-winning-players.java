class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int [][]freqs= new int[11][11];
        for(int i=0; i<pick.length; i++){
            freqs[pick[i][0]][pick[i][1]]++;
        }
        int res=0;
        for(int i=0; i<=10; i++){
            for(int j=0; j<=10; j++){
                if(freqs[i][j]>= i+1){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}