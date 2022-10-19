class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        vector<string> ans;
        map<int,vector<string>> mp;
        int cnt=0;
        string str= words[0];
        for(int i=0; i<words.size(); i++){ 
            if(str==words[i]){
                cnt++;
            }else{
                mp[cnt].push_back(str);
                str=words[i];
                cnt=1;
            }
        }
        if(cnt>0){
            mp[cnt].push_back(str);
        }
        for(auto i= mp.rbegin(); i!= mp.rend() && k>0; i++){
            for(auto j: i->second){
                ans.push_back(j);
                k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};