class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto i: nums) {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(),[](string &a, string &b){return a+b<b+a;});
        string ans="";
        while(strs.size()>1 && strs.back()=="0") strs.pop_back();
        for(int i=strs.size()-1; i>=0; i--) ans+= strs[i];
        return ans;
    }
};