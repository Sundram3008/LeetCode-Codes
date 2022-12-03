class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++) mp[s[i]]++;
        map<int, vector<char>> mp1;
        for(auto i: mp){
            mp1[i.second].push_back(i.first);
        }
        string ans="";
        for(auto i= mp1.rbegin(); i!= mp1.rend(); i++){
            for(auto j: i->second){
                int x= i->first;
                while(x--){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};