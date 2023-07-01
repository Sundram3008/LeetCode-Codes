class Solution {
public:
    int ans=INT_MAX;
    void helper(int idx, int k, vector<int> &c, vector<int> &dis){
        if(idx==c.size()){
            ans= min(ans, *max_element(dis.begin(), dis.end()));
            return ;
        }
        for(int i=0; i<k; i++){
            dis[i]+= c[idx];
            helper(idx+1, k, c, dis);
            dis[i]-= c[idx];
            if(dis[i]==0) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dis(k,0);
        helper(0, k, cookies, dis);
        return ans;
    }
};