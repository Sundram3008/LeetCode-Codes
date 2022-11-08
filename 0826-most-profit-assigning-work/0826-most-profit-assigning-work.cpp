class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& w) {
        //Good But better is next one
        // map<int,int> mp;
        // mp[0]=0;
        // for(int i=0; i<diff.size(); i++){
        //     if(mp.find(diff[i])!= mp.end()) mp[diff[i]]= max(mp[diff[i]], pro[i]);
        //     else mp[diff[i]]= pro[i];
        // }
        // int maxi= mp.begin()->second;
        // for(auto &i: mp){
        //     if(i.second> maxi) maxi=i.second;
        //     else i.second= maxi;
        // }
        // int ans=0;
        // for(auto i : w){
        //     if(mp.find(i)!=mp.end()) ans+= mp[i];
        //     else {
        //         mp[i]=1000;
        //         auto x= --mp.find(i);
        //         ans+= x->second;
        //         mp.erase(i);
        //     }
        // }
        // return ans;
        vector<pair<int,int>> v;
        int n= diff.size(), ans=0, j=0,maxi=0;
        for(int i=0; i<n; i++) v.push_back({diff[i],pro[i]});
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        for(auto i: w){
            while(j<n && v[j].first<=i){
                maxi= max(maxi, v[j++].second);
            }
            ans+= maxi;
        }
        return ans;
    }
};