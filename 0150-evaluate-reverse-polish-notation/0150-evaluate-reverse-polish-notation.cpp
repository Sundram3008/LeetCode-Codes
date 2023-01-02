class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(int i=0; i<tokens.size(); i++){
            long a,b;
            if(tokens[i]=="+"){
                a= st.top();
                st.pop();
                b= st.top();
                st.pop();
                st.push(b+a);
            }
            else if(tokens[i]=="-"){
                a= st.top();
                st.pop();
                b= st.top();
                st.pop();
                st.push(b-a);
            }
            else if(tokens[i]=="*"){
                a= st.top();
                st.pop();
                b= st.top();
                st.pop();
                st.push(b*a);
            }
            else if(tokens[i]=="/"){
                a= st.top();
                st.pop();
                b= st.top();
                st.pop();
                st.push(b/a);
            }else {
                a= stol(tokens[i]);
                st.push(a);
            }
        }
        return st.top();
    }
};