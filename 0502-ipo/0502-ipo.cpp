class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vp;
        for(int i=0; i<profits.size(); i++) vp.push_back({capital[i], profits[i]});
        sort(vp.begin(), vp.end());
        int i=0;
        priority_queue<int> valPq;
        while(k>0){
            for(;i<vp.size(); i++){
                if(vp[i].first<= w){
                    valPq.push(vp[i].second);
                }else break;
            }
            if(!valPq.empty()){
                w+= valPq.top();
                valPq.pop();
                k--;
            }else return w;
        }
        return w;
    }
};