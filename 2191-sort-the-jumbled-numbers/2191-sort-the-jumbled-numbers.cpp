class Solution {
public:
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> vals;
        for(int i=0; i<nums.size(); i++){
            int num= nums[i];
            string temp= to_string(num);
            string ctemp="";
            for(int j=0; j<temp.size(); j++){
                ctemp+= to_string(mapping[temp[j]-'0']);
            }
            vals.push_back({stoi(ctemp),i});
        }
        sort(vals.begin(), vals.end());
        vector<int> ans;
        for(auto i: vals){
            ans.push_back(nums[i.second]);
        }
        return ans;
    }
};