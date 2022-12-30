class Solution {
public:
    static bool mycomp(const vector<int> &a, const vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& ins) {
        sort(ins.begin(), ins.end(), mycomp);
        int end=ins[0][1], ans=0;
        for(int i=1; i<ins.size(); i++){
            if(end> ins[i][0]) ans++;
            else end= ins[i][1];
        }
        return ans;
    }
};