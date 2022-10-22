class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp,sp;
        for(auto i:t) mp[i]++;
        int i=-1, j=-1, cnt=0, n=s.size(), m=t.size();
        string ans="";
        while(i<=j){
            bool flag1=false,flag2=false;
            while(j<n && cnt <m){
                j++;
                sp[s[j]]++;
                if(sp[s[j]]<= mp[s[j]]) cnt++;
                flag1=true;
            }
            while(i<j && cnt==m){
                if(ans.size()==0 || j-i<ans.size()){
                    ans= s.substr(i+1,j-i);
                }
                i++;
                --sp[s[i]];
                if(sp[s[i]]< mp[s[i]]) cnt--;
                flag2=true;
            }
            if(!flag1 && !flag2) break;
        }
        return ans;
    }
};