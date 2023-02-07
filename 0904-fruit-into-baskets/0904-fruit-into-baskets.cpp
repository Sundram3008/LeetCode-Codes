class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j=0;
        unordered_map<int,int> mp;
        int dist=0,ans=0;
        for(int i=0; i<fruits.size(); i++){
            mp[fruits[i]]++;
            if(mp[fruits[i]]==1) dist++;
            if(dist>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0) dist--;
                j++;
            }
            ans= max(ans, i-j+1);
        }
        return ans;
    }
};