class Solution {
    public int countHomogenous(String s) {
        long curr=1, ans=0;
        int mod= (int)1e9+7;
        for(int i=1; i<s.length(); i++){
            if(s.charAt(i)==s.charAt(i-1)) curr++;
            else{
                ans+= (curr * (curr+1)/2)%mod;
                curr=1;
            }
        }
        ans+= (curr * (curr+1)/2)%mod;
        return (int)ans;
    }
}