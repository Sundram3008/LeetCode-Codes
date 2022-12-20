class Solution {
public:
    pair<int, int> factors(int &n){
        vector<int> v;
        int sum=0;
        while(n%2==0){
            v.push_back(2);
            n/=2;
        }
        for(int i=3; i<= sqrt(n); i+=2){
            while(n%i==0){
                v.push_back(i);
                n/=i;
            }
        }
        if(n>2) v.push_back(n);
        for(auto i: v) sum+=i;
        return {sum, v.size()};
    }
    int smallestValue(int n) {
        if(n==4) return n;
        pair<int,int> p= factors(n);
        int sum= p.first;
        int v= p.second;
        while(v>1){
            p= factors(sum);
            sum= p.first;
            v= p.second;
        }
        return sum;
    }
};