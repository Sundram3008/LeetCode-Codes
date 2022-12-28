class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        long sum=0;
        for(int i=0; i<piles.size(); i++) pq.push(piles[i]), sum+=piles[i];
        while(k--){
            int x= pq.top();
            pq.pop();
            pq.push(x-(x/2));
            sum-=(x/2);
        }
        return sum;
        
    }
};