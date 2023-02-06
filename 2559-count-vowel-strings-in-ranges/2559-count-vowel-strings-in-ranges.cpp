class Solution {
public:
    bool vow(char ch){
        return (ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> mp(words.size(), 0);
        for(int i=0; i<words.size(); i++){
            char start = words[i][0], end= words[i].back();
            if(vow(start) && vow(end))
                mp[i]=1;
        }
        int x=0;
        for(auto &i: mp){
            i+= x;
            //cout<<i<<endl;
            x= i;
        }
        vector<int> ans;
        for(auto i: queries){
            i[0]-=1;
            if(i[0]>=0)
            ans.push_back(mp[i[1]]-mp[i[0]]);
            else ans.push_back(mp[i[1]]);
        }
        return ans;
    }
};