class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        int lowSize=0, highSize=0;
        int tempLow=low, tempHigh=high;
        
        List<Integer> res = new ArrayList<>();
        while(tempLow>0){
            tempLow/=10;
            lowSize++;
        }
        while(tempHigh>0){
            highSize++;
            tempHigh/=10;
        }
        
        for(int i=lowSize; i<=highSize; i++){
            for(int j=1; j<=9; j++){
                int cnt=0, l=j, num=0;
                while(cnt<i && l<=9){
                    num*=10;
                    num+=l;
                    l++;
                    cnt++;
                } 
                if(cnt==i && num<=high && num>=low) res.add(num);
            }
        }
        return res;
    }
}