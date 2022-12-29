#define pp pair<long long int,long long int>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i=0; i<tasks.size(); i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        long i=0, time=0;
        vector<int> ans;
        while(i<tasks.size() || pq.size()){
            if(pq.empty()){
                time= max(time, (long)tasks[i][0]);
            }
            while(i<tasks.size() && tasks[i][0]<= time){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            time+= pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};