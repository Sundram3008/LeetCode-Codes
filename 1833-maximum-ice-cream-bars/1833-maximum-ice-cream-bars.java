class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int ans=0, sum=0;
        Arrays.sort(costs);
        for(int i: costs){
            sum+= i;
            if(sum>coins) return ans;
            ans++;
        }
        return ans;
    }
}