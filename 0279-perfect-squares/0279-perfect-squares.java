class Solution {
    public int helper(int idx, ArrayList<Integer> vals, int n, int[] dp){
        if(idx==vals.size()){
            if(n==0) return 0;
            else return 10001;
        }
        if(dp[n]!= 10001) return dp[n];
        int mini= 10001;
        if(n>= vals.get(idx)) mini = Math.min(mini, helper(idx, vals, n-vals.get(idx), dp))+1;
        mini = Math.min(mini, helper(idx+1, vals, n, dp));
        dp[n]= mini;
        return mini;
    }
    public int numSquares(int n) {
        ArrayList<Integer> vals = new ArrayList<>();
        for(int i=1; i<=Math.pow(n, 0.5); i++){
            vals.add(i*i);
        }
        int []dp = new int[n+1];
            for(int j=0; j<=n; j++) dp[j]=10001;
        return helper(0, vals, n, dp);
    }
}