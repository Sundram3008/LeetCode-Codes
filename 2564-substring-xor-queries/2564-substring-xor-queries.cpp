class Solution {
#define ll long long
    unordered_map<ll,vector<int>> mp;
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int val= min(31, (int)s.length());
        for(int i=1; i<=val; i++){
            vals(i,s);
        }
        vector<vector<int>> ans;
        for(auto i: queries){
            if(mp.find(i[0]^i[1])!=mp.end()){
                ans.push_back(mp[i[0]^i[1]]);
            }
            else ans.push_back({-1,-1});
        }
        return ans;
    }
private:
    void vals(int k, string &s){
        deque<ll> q;
        // from second
        int i=0;
        for(i=0; i<s.length(); i++){
            if(i>=k){
                ll val=0, cnt=0;
                for(auto j: q){
                    cnt++;
                    val+= (j*pow(2,(int)q.size()-cnt));
                }
                if(mp.find(val)==mp.end()){
                    mp[val]= {i-(int)q.size(),i-1};
                }
                q.pop_front();
            }
            if(s[i]=='0')
            q.push_back(0);
            else q.push_back(1);
        }
        ll val=0, cnt=0;
        for(auto j: q){
            cnt++;
            val+= (j*pow(2,(int)q.size()-cnt));
        }
        if(mp.find(val)==mp.end()){
            mp[val]= {i-(int)q.size(),i-1};
        }
        return;
    }
};