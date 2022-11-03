class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto i: words) mp[i]++;
        int cnt=0;
        for(auto i: words){
            string temp=i;
            reverse(temp.begin(), temp.end());
            mp[i]-=1;
            if(mp[i]>=0 && mp[temp]>=1){
                mp[temp]-=1;
                cnt+=4;
            }else mp[i]+=1;
        }
        for(auto i: mp){
            string temp=i.first;
            reverse(temp.begin(), temp.end());
            if(temp== i.first && mp[temp]>=1){ 
                cnt+=2;
                break;
            }
        }
        return cnt;
    }
};