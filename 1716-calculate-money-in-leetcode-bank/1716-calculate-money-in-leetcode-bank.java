class Solution {
    public int totalMoney(int n) {
        int ans=0;
        int curr=1, x=1;
        for(int i=1; i<=n; i++){
            ans+= x;
            x++;
            if(i%7==0){
                curr++;
                x=curr;
            }
        }
        return ans;
    }
}