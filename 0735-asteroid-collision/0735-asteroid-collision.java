class Solution {
    public int[] asteroidCollision(int[] astds) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(int i=0; i<astds.length; i++){
            int astd= astds[i];
            if(astd <0){
                int prev=0;
                boolean dest=false;
                if(res.size()>0) prev= res.get(res.size()-1);
                while(res.size()>0 && prev > 0 && -1* astd >= prev){
                    res.remove(res.size()-1);
                    if(prev==-1*astd){
                        dest=true;
                        break;
                    }
                    if(res.size()>0) prev = res.get(res.size()-1);
                }
                if((res.size()==0 || prev<0 ) && !dest) res.add(astd);
            }else {
                res.add(astd);
            }
        }
        int [] ans= new int[res.size()];
        int j=0;
        for(int i: res){
            ans[j++]=i;
        }
        return ans;
    }
}