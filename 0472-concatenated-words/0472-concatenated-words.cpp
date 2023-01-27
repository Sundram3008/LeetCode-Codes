class Solution {
public:
    vector<string> ans;
    unordered_map<string, bool> mp;
    bool exists(string s){
        for(int i=1; i<s.size(); i++){
            string x= s.substr(0,i);
            string t= s.substr(i);
            if(mp.find(x)!= mp.end() && (mp.find(t)!= mp.end() || exists(t))){
                mp[t]=true;
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto i: words){
            mp[i]=true;
        }
        for(auto i: words){
            //mp[i]=false;
            if(exists(i)){
                ans.push_back(i);
            }
            //mp[i]=true;
        }
        return ans;
    }
};