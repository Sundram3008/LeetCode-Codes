class Solution {
public:
    static bool myComp(pair<int, int> &a, pair<int, int> &b){
        if(a.second!= b.second){
            return a.second> b.second;
        }else return a.first>b.first;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vp;
        for(int i=0; i<plantTime.size(); i++){
            vp.push_back(make_pair(plantTime[i],growTime[i]));
        }
        sort(vp.begin(), vp.end(), myComp);
        int delay=-1, ans=0;
        for(auto i: vp){
            delay += i.first;
            ans=max(ans, delay+i.second+1);
        }
        return ans;
    }
};