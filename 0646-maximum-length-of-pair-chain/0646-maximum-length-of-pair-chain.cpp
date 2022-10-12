class Solution {
public:
    static bool mysort(vector<int> &a, vector<int> &b){
        if(a[1]!=b[1]) return a[1]<b[1];
        else return a[0]<b[0];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), mysort);
        int cnt=0, prev=INT_MIN;
        for(auto i: pairs){
            if(i[0]>prev){
                prev=i[1];
                cnt++;
            }
        }
        return cnt;
    }
};