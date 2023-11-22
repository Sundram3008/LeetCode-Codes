class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // int r= nums.size(), c= 0;
        // for(auto &i: nums) c= max(c, (int)i.size());
        // vector<int> ans;
        // for(int i=0; i<r; i++){
        //     int a=i, b=0;
        //     while(a>=0 && b<c){
        //         if(b< nums[a].size()) ans.push_back(nums[a][b]);
        //         a--;
        //         b++;
        //     }
        // }
        // for(int i=1; i<c; i++){
        //     int a=r-1, b= i;
        //     while(a>=0 && b<c){
        //         if(b< nums[a].size()) ans.push_back(nums[a][b]);
        //         a--;
        //         b++;
        //     }
        // }
        // return ans;
        unordered_map<int, vector<int>> mp;
        int maxVal=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
                maxVal= max(maxVal, i+j);
            }
        }
        vector<int> ans;
        for(int i=0; i<=maxVal; i++){
            for(auto j= mp[i].rbegin(); j!= mp[i].rend(); j++) ans.push_back(*j);
        }
        return ans;
    }
};