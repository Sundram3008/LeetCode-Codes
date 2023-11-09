class Solution {
    public int countHomogenous(String s) {
        int curr=1, ans=1;
        int mod= (int)1e9+7;
        for(int i=1; i<s.length(); i++){
            if(s.charAt(i)==s.charAt(i-1)) curr++;
            else curr=1;
            ans= (ans+curr)%mod;
        }
        return ans;
    }
}