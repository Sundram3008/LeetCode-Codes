class Solution {
    public int buyChoco(int[] prices, int money) {
        int mini1= Integer.MAX_VALUE, mini2= Integer.MAX_VALUE;
        for(int i=0; i<prices.length; i++){
            if(mini1> prices[i]){
                mini2= mini1;
                mini1= prices[i];
            }else if(mini2> prices[i]) mini2= prices[i];
        }
        return (mini1+mini2>money)? money: money- (mini1+mini2);
    }
}