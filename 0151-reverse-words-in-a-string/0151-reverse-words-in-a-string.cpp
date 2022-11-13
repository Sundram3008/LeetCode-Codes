class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==' '){
                if(temp.size()>0){
                    reverse(temp.begin(), temp.end());
                    ans+= temp+ " ";
                }
                temp="";
            }else temp.push_back(s[i]);
        }
        if(temp.size()>0){
            reverse(temp.begin(), temp.end());
            ans+= temp;
        }
        if(ans.back()==' ') ans.pop_back();
        return ans;
    }
};