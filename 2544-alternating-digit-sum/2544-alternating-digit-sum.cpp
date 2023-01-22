class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        int sign=0, sum=0;
        while(n>0){
            v.push_back(n%10);
            n/=10;
        }
        for(int i=v.size()-1; i>=0; i--){
            if(sign%2==0){
                sum+= v[i];
            }else{
                sum-= v[i];
            }
            sign++;
        }
        return sum;
    }
};