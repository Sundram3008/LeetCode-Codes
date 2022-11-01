class Solution {
public:
    int maximumSwap(int num) {
        vector<int> n;
        int x=num;
        while(x>0){
            n.push_back(x%10);
            x/=10;
        }
        reverse(n.begin(), n.end());
        int ans=0, val=INT_MIN, idx=-1;
        bool flag=true;
        for(int i=0; i<n.size() && flag; i++){
            for(int j=n.size()-1; j>i; j--){
                if(n[j]>n[i] && n[j]>val){
                    val=n[j];
                    idx=j;
                }
            }
            if(val>n[i]){
                swap(n[i],n[idx]);
                break;
            }
        }
        for(int i=0; i<n.size(); i++)
            ans=(ans*10) + n[i];
        return ans;
    }
};