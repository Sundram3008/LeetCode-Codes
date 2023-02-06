class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i: nums){
            vector<int> temp;
            while(i>0){
                temp.push_back(i%10);
                i/=10;
            }
            reverse(temp.begin(), temp.end());
            for(auto j: temp) ans.push_back(j);
        }
        return ans;
    }
};