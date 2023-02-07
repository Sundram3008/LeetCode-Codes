class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        deque<int> q;
        map<int,int> mp;
        int dist=0,ans=0;
        for(auto i: fruits){
            q.push_back(i);
            mp[i]++;
            if(mp[i]==1) dist++;
            if(dist>2){
                mp[q.front()]--;
                if(mp[q.front()]==0) dist--;
                q.pop_front();
            }
            ans= max(ans, (int)q.size());
        }
        return ans;
    }
};