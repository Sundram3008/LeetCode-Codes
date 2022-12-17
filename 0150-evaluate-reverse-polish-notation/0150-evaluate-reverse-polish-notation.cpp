class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long > st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                long a= st.top();
                st.pop();
                long b= st.top();
                st.pop();
                st.push(b+a);
            }else if(tokens[i]=="-"){
                long a= st.top();
                st.pop();
                long b= st.top();
                st.pop();
                st.push(b-a);
            }else if(tokens[i]=="*"){
                long a= st.top();
                st.pop();
                long b= st.top();
                st.pop();
                st.push(b*a);
            }else if(tokens[i]=="/"){
                long a= st.top();
                st.pop();
                long b= st.top();
                st.pop();
                st.push(b/a);
            }else{
                st.push(stol(tokens[i]));
            }  
        }
        return st.top();
    }
};