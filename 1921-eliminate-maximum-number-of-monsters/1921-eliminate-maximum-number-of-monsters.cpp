class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        map<double, int> mp;
        for(int i=0; i<dist.size(); i++) mp[(1.0*dist[i])/speed[i]]++;
        double time=0;
        int res=0;
        for(auto i: mp){
            int x= i.second;
            while(x>0){
                if(i.first <= time) return max(res, 1);
                x--;
                time++;
                res++;
            }
        }
        return max(res, 1);
    }
};