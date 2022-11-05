class Solution {
public:

    bool isPalindrome(string s){
        int l=0, r=s.size()-1;
        while(l<r) if(s[l++]!=s[r--]) return false;
        return true;
    }
    void helper(string s, int i, vector<vector<string>> &ans, vector<string> &temp){
        if(i==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int j=i; j<s.length(); j++){
            string t= s.substr(i,j-i+1);
            if(isPalindrome(t)){
                temp.push_back(t);
                helper(s,j+1,ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(s,0,ans, temp);
        return ans;
    }
};