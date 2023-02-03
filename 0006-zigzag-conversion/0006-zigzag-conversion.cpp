class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> strs(numRows, "");
        int row=0;
        bool down=true;
        for(auto i: s){
            strs[row].push_back(i);
            if(row == 0) down = true;
            if(row == numRows-1) down = false;
            (down)? row++:row--;
        }
        string ans="";
        for(auto i: strs) ans+= i;
        return ans;
    }
};