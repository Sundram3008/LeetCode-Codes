class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> included(26,false);
        vector<int> lastP(26,0);
        for(int i=0; i<s.length(); i++){
            lastP[s[i]-'a']=i;
        }
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            int curr= s[i]-'a';
            if(included[curr]) continue;
            while(!st.empty() && curr<st.top() && i<lastP[st.top()]){
                included[st.top()]=false;
                st.pop();
            }
            st.push(curr);
            included[curr]=true;
        }
        string ans="";
        while(!st.empty()){
            ans= char(st.top()+'a')+ans;
            st.pop();
        }
        return ans;
    }
};