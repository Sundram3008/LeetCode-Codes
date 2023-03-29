class Solution {
public:
    int maxSatisfaction(vector<int>& sats) {
        sort(sats.begin(), sats.end());
        int ans=0, n = sats.size(), total=0;
        for(int i = n-1; i>=0 && sats[i]+total >0; i--){
            total+= sats[i];
            ans+= total;
        }
        return ans;
//         for(int i=0; i<sats.size(); i++){
//             int cnt=1, tcnt=0;
//             for(int j=i; j<sats.size(); j++){
//                 tcnt+= (sats[j]*cnt);
//                 cnt++;
//                 ans= max(ans, tcnt);
//             }
            
//         }
//         return ans;
    }
};