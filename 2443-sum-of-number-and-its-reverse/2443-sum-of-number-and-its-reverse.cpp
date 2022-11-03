class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int j=0; j<=num/2+1; j++){
            int x=num-j, ans=0;
            while(x>0){
                ans*=10;
                ans+= x%10;
                x/=10;
            }
            if(j==ans) return true;
        }
        return false;
    }
};