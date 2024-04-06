class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<pair<char,int>> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(') st.push({'(',i});
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else s[i]='*';
            }
        }
        while(!st.empty()) {
            s[st.top().second]='*';
            st.pop();
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]!='*') ans.push_back(s[i]);
        }
        return ans;
    }
};