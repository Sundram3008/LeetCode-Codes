class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0 ) return true;
        if(flowerbed.size()==1){
            if(flowerbed[0]==0) return (n-1==0);
            else return false;
        }
        for(int i=0; i<flowerbed.size(); i++){
            if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
            else if(i==flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]==0 ){
                flowerbed[i]=1;
                n--;
            }
            else if(i-1>=0 && i+1< flowerbed.size() && flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                n--;
            }
            if(n==0) return true;
        }
        if(n>0) return false;
        else return true;
    }
};