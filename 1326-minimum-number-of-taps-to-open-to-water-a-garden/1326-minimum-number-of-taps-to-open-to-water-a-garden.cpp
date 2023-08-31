class Solution {
public:
    static bool mycomp(const vector<int> &a, const vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> rgs;
        for(int i=0; i<ranges.size(); i++){
            rgs.push_back({max(0, i-ranges[i]), i+ranges[i]});
        }
        sort(rgs.begin(), rgs.end(), mycomp);
        if(rgs[0][0]!=0) return -1;
        int reach =rgs[0][1], maxreach=rgs[0][1], ans=1;
        for(int i=1; i<rgs.size(); i++){
            if(reach>= rgs[i][0]) maxreach= max(maxreach, rgs[i][1]);
            if(reach <= rgs[i][0]){
                if(maxreach>= rgs[i][0]){
                    if(maxreach>reach)
                        ans++;
                }else return -1;
                reach=maxreach;
                maxreach= max(maxreach, rgs[i][1]);
            }
        }
        if(reach<n && maxreach>=n) return ans+1;
        return (reach>=n)? ans: -1;
    }
};