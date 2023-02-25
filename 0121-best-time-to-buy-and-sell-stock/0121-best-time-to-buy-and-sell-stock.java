class Solution {
    public int maxProfit(int[] prices) {
        int mini=prices[0], ans=0;
        for(int i=0; i<prices.length; i++) {
            if(prices[i]-mini > ans)
                ans= prices[i]-mini;
            mini= Math.min(prices[i], mini);
        }
        return ans;
    }
}