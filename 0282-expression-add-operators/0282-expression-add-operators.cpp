class Solution {
public:
    vector<string> ans;
    void helper(string &s, string path, int idx, long x1, long x2, int &target){
        if(idx>= s.length()){
            if(x1==target) ans.push_back(path);
            return ;
        }
        string currpath="";
        long currnum=0;
        for(int i=idx; i<s.length(); i++){
            if(i>idx && s[idx]=='0') break;
            currpath+= s[i];
            currnum=(currnum*10) +(s[i]-'0');
            if(idx==0){
                helper(s, path+currpath, i+1, currnum, currnum, target);
            }
            else{
                helper(s, path+"+"+currpath, i+1, x1+currnum, currnum, target);
                helper(s, path+"-"+currpath, i+1, x1-currnum, -currnum, target);
                helper(s, path+"*"+currpath, i+1, x1-x2 + x2*currnum, x2*currnum, target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        helper(num, "", 0, 0, 0, target);
        return ans;
    }
};