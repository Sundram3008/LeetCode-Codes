class Solution {
public:
    vector<int> asteroidCollision(vector<int>& atds) {
        stack<int> st;
        vector<int> ans(atds.size(), 0);
        vector<int> res;
        for(int i=0; i<atds.size(); i++){
            if(atds[i]<0){
                while(!st.empty() && -1*atds[i] >= atds[st.top()]){
                    ans[st.top()]=-1;
                    if(-1*atds[i]==atds[st.top()]){
                        ans[i]=-1;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(!st.empty()) ans[i]=-1;
            }else{
                st.push(i);
            }
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!=-1) res.push_back(atds[i]);
        }
        return res;
    }
};