class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size()==1) return votes[0];
        vector<vector<pair<int,char>>> arr(26);
        for(int i=0; i<votes.size(); i++)
            for(int j=0; j<votes[i].size(); j++)
                arr[votes[i][j]-'A'].push_back(make_pair(j,votes[i][j]));
        
        for(int i=0; i<26; i++)
            sort(arr[i].begin(), arr[i].end());
        vector<pair<string,char>> v(26);
        string ans="";
        for(int i=0; i<26; i++){
            for(auto j: arr[i]){
                v[i].first= v[i].first+ to_string(j.first);
                v[i].second= j.second;
            }
        }
        sort(v.begin(),v.end());
        for(auto i: v)
            if(i.first.size()>0)
                ans+= i.second;
        return ans;
    }
};