class Solution {
public:
    void allCombs(int idx, string &digs, string &temp, vector<string> &v, vector<string> &ans){
        if(idx==digs.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i<v[(digs[idx]-'0')-2].size(); i++){
            temp.push_back(v[(digs[idx]-'0')-2][i]);
            allCombs(idx+1, digs, temp, v, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> v= {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp="";
        allCombs(0, digits, temp, v, ans);
        return ans;
    }
};