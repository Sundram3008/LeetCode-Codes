class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& pot, long long success) {
        vector<pair<int,int>> nsp;
        for(int i=0; i<sp.size(); i++){
            nsp.push_back({sp[i],i});
        }
        sort(nsp.begin(), nsp.end());
        sort(pot.begin(), pot.end());
        vector<int> ans(nsp.size(),0);
        int j=pot.size()-1;
        for(int i=0; i<nsp.size(); i++){
            while(j>=0 && 1LL*nsp[i].first*pot[j]>=success) j--;
            ans[nsp[i].second]= (pot.size() -(j+1));
        }
        return ans;
    }
};