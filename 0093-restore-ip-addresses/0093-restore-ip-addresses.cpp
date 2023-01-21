class Solution {
public:
    // recursion based 
    set<string> ans;
    void backTrack(string s, int idx, int n, vector<int> &temp){
        if(temp.size()==4){
            // check valid ip
            int x=0;
            string res="";
            for(auto i: temp){
                string val= "";
                for(int j=x; j<=i; j++){
                    val.push_back(s[j]);
                }
                x=i+1;
                if(temp.back()==i){
                    for(int j=i+1; j<n; j++) val.push_back(s[j]);
                }
                if(val[0]=='0' && val.size()>1){
                    return ;
                }
                long long int intVal= stoll(val);
                if(intVal>255 || intVal<0) return;
                res+= val+".";
            }
            res.pop_back();
            ans.insert(res);
            return;
        }
        if(idx>=n) return;
        for(int i=idx; i<n; i++){
            temp.push_back(i);
            backTrack(s, i+1, n, temp);
            temp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<int> temp;
        backTrack(s, 0, s.size(), temp);
        vector<string> res;
        for(auto i: ans) res.push_back(i);
        return res;
    }
    
};