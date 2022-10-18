class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1; i<n; i++){
            vector<pair<int,char>> v;
            char ch= ans[0];
            int cnt=0;
            for(int j=0; j<ans.size(); j++){
                if(ch==ans[j]){
                    cnt++;
                }else{
                    v.push_back({cnt,ch});
                    ch=ans[j];
                    cnt=1;
                }
            }
            if(cnt>0){
                v.push_back({cnt,ch});
            }
            ans="";
            for(auto j:v){
                ans= ans + to_string(j.first)+ j.second;
            }
        }
        return ans;
    }
};