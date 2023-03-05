class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while(num>0) v.push_back(num%10), num/=10;
        sort(v.begin(), v.end());
        int a=0, b=0;
        for(int i=0; i<v.size(); i++){
            if(i%2==0){
                a= (a*10)+ v[i];
            }else b= (b*10)+v[i];
        }
        return a+b;
    }
};