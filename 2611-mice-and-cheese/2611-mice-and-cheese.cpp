class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int, int>> diff(reward1.size());
        for(int i=0; i<reward1.size(); i++){
            diff[i]= {reward1[i]-reward2[i], i};
        }
        int ans=0, cnt=0;
        sort(diff.begin(), diff.end());
        for(int i=diff.size()-1; i>=0; i--){
            if(cnt>=k){
                ans+= reward2[diff[i].second];
            }else{
                cnt++;
                ans+= reward1[diff[i].second];
            }
        }
        return ans;
    }
};