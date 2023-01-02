class Solution {
public:
    void help(vector<vector<int>> &ans, vector<int> temp, int n, int k){
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        for(int i= (temp.empty())?1: temp.back()+1; i<=9; i++){
            if(n-i <0) break;
            temp.push_back(i);
            help(ans, temp, n-i, k);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(ans, temp, n, k);
        return ans;
    }
};