class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        list<int> idxs(deck.size());
        iota(idxs.begin(), idxs.end(),0);
        int fill=1;
        vector<int> ans(deck.size(),0);
        auto idx= idxs.begin();
        for(int i=0; !idxs.empty(); fill= !fill){
            if(idx==idxs.end()) idx= idxs.begin();
            if(fill){
                ans[*idx] = deck[i++];
                idxs.erase(idx++);
            }else
            idx++;
        }
        return ans;
    }
};