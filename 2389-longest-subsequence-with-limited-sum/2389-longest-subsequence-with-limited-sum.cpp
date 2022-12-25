class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<queries.size(); i++){
            int sum=0,cnt=0;
            for(auto j: nums){
                sum+=j;
                if(sum> queries[i]){
                    break;
                }
                else cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};