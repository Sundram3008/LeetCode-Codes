class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int choc1=INT_MAX, choc2= INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<choc1){
                choc2= choc1;
                choc1= prices[i];
            }
            else if(prices[i]<choc2) choc2= prices[i];
        }
        if(choc1+ choc2> money) return money;
        return money- choc1- choc2;
    }
};