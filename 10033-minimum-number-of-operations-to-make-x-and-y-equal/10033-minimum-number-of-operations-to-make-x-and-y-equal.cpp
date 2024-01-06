class Solution {
public: 
    
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> st;
        queue<int> q;
        int op=0;
        q.push(x);
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                int a= q.front();
                q.pop();
                if(a==y) return op;
                if(a%5 ==0 && st.find(a/5)==st.end()){
                    q.push(a/5);
                    st.insert(a/5);
                }
                if(st.find(a+1)==st.end()){
                    q.push(a+1);
                    st.insert(a+1);
                }
                if(a%11 ==0 && st.find(a/11)==st.end()){
                    q.push(a/11);
                    st.insert(a/11);
                }
                if(a-1 >=1 && st.find(a-1)==st.end()){
                    q.push(a-1);
                    st.insert(a-1);
                }
            }
            op++;
        }
        return op;
    }
};