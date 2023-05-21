class Solution {
public:
    
    bool rec(int x, int i, vector<int> &v, int sum){
        if(sum>x) return false;
        if(i>=v.size()){
            if(sum==x) return true;
            else return false;
        }
        int k=0;
        for(int j=i; j<v.size(); j++){
            k*=10;
            k+=v[j];
            if(rec(x, j+1, v, sum+k)) return true;
        }
        return false;
    }
    bool yes(int x, int i){
        vector<int> v;
        while(x>0){
            v.push_back(x%10);
            x/=10;
        }
        reverse(v.begin(), v.end());
        return rec(i, 0, v, 0);
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1; i<=n; i++){
            int x= i*i;
            if(yes(x, i)){
                //cout<<x<<endl;
                sum+=x;
            }
        }
        return sum;
    }
};