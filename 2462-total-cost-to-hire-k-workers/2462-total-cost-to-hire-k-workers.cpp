#define ll long long
#define pp priority_queue<int, vector<int>, greater<int>> 
class Solution {
public:
    long long totalCost(vector<int>& v, int k, int c) {
        pp l, r;
        int n=v.size(),i=0, j=n-1;
        ll sum=0;
        while(k--){
            while(i<=j && l.size()<c){ 
                l.push(v[i]);
                i++;
            }
            while(j>=i && r.size()<c ){
                r.push(v[j]);
                j--;
            }
            int a= (l.size()>0)? l.top(): INT_MAX;
            int b= (r.size()>0)? r.top(): INT_MAX;
            if(a<=b){
                sum+= a;
                l.pop();
            }else{
                sum+= b;
                r.pop();
            }
        }
        return sum;
    }
};