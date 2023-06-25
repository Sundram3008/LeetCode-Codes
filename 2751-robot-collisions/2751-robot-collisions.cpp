class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        vector<pair<int,int>> vp;
        for(int i=0; i<pos.size(); i++) vp.push_back({pos[i], i});
        sort(vp.begin(), vp.end());
        stack<int> ls, rs;
        for(int i=0; i<vp.size(); i++){
            int idx= vp[i].second;
            if(dir[idx]=='L'){
                ls.push(idx);
                while(!rs.empty()){
                    auto x= rs.top();
                    if(h[x]> h[idx]){
                        h[x]-=1;
                        h[idx]=INT_MIN;
                        ls.pop();
                        break;
                    }else if(h[x]<h[idx]){
                        h[idx]-=1;
                        h[x]=INT_MIN;
                        rs.pop();
                    }else{
                        h[x]=INT_MIN;
                        h[idx]=INT_MIN;
                        ls.pop();
                        rs.pop();
                        break;
                    }
                }
            }
            else{
                rs.push(idx);
            }
        }
        vector<int> ans;
        for(auto &i: h){
            if(i!=INT_MIN) ans.push_back(i);
        }
        return ans;
    }
};