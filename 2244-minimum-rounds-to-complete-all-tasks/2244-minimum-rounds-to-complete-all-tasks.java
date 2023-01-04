class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> mp= new HashMap<Integer, Integer>();
        for(int i: tasks){ 
            Integer x = mp.getOrDefault(i,0);
            mp.put(i,x+1);
        }
        int ans=0;
        for(Map.Entry m: mp.entrySet()){
            Integer val= (Integer)m.getValue();
            while(val>0 && val>1){
                if(val%3==0){
                    val-=3;
                    ans++;
                }
                else if(val%2==0){
                   val-=2;
                    ans++;
                }else{
                    val-=3;
                    ans++;
                }
            }
            if(val==1) return -1;
        }
        return ans;
    }
}