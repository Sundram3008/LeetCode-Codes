class Solution {
public:
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &mp){
        if(i>= prices.size()) return 0;
        if(mp[i][buy]!=-1) return mp[i][buy];
        int cooldown= f(i+1, buy, prices, mp);
        if(buy==1){
            int g= f(i+1, 0, prices, mp)- prices[i];
            mp[i][buy]= max(g,cooldown);
        }
        else {
            int sell= f(i+2, 1, prices, mp)+prices[i];
            mp[i][buy]= max(sell, cooldown);
        }
        return mp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> mp(prices.size()+2,vector<int>(2,-1));
        return f(0,1,prices,mp);
    }
};