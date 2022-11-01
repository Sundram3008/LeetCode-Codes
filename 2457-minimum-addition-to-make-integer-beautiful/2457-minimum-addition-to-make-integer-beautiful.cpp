class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long int dig=0, x=-1, p=1,y=n,t,ans=0;
        while(y>0){
            dig+= (y%10);
            y/=10;
        }
        while(dig>target){
            y=n;
            t= pow(10,p);
            p+=1;
            y/=t;
            y+=1;
            y*=t;
            dig=0;
            ans= abs(y-n);
            while(y>0){
                dig+= (y%10);
                y/=10;
            }
        }
        return ans;
    }
};