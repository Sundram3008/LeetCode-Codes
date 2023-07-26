class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int ls=1, hs=10000000, ans= (int)1e7+1;
        while(ls<=hs){
            int s= ls+ ((hs-ls)/2);
            double tt=0;
            for(int i: dist){
                tt= Math.ceil(tt);
                tt+= (1.0*i/s);
                if(tt>hour) break;
            }
            if(tt<= hour){
                ans=s;
                hs=s-1;
            }else ls=s+1;
        }
        return (ans>(int)1e7)? -1 : ans;
    }
}