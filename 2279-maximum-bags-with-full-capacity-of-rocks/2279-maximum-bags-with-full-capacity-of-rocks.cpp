class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& r, int a) {
        vector<int> rem;
        for(int i=0; i<cap.size(); i++) rem.push_back(cap[i]-r[i]);
        sort(rem.begin(), rem.end());
        int i=0, cnt=0;
        while(i<rem.size() && a>0){
            if(rem[i]<= a){ 
                a-=rem[i];
                cnt++;
            }else return cnt;
            i++;
        }
        return cnt;
    }
};