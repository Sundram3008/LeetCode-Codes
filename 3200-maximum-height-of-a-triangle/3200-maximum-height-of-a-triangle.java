class Solution {
    
    public int maxHeightOfTriangle(int red, int blue) {
        int cnt1=0, rt= red, bt= blue, cnt2=0;
        for(int i=1; true; i++){
            if(i%2==1){
                if(rt<i) break;
                rt-=i;
            }else{
                if(bt<i) break;
                bt-=i;
            }
            cnt1++;
        }
        for(int i=1; true; i++){
            if(i%2==0){
                if(red<i) break;
                red-=i;
            }else{
                if(blue<i) break;
                blue-=i;
            }
            cnt2++;
        }
        return Math.max(cnt1, cnt2);
    }
}