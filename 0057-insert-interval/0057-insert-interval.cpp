class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& ni) {
        if(is.size()==0){
            return{ni};
        }
        vector<vector<int>> ans;
        bool flag=true;
        for(int i=0; i<is.size(); i++){
            if((is[i][1]>=ni[0] && is[i][0] <= ni[0]) || (is[i][0]<= ni[1] && is[i][1] >= ni[1])){
                is[i][1]= max(is[i][1], ni[1]);
                is[i][0]= min(is[i][0], ni[0]);
                flag=false;
                break;
            }else if(ni[0]<= is[i][0] && ni[1]>= is[i][1]){
                is[i][0]= ni[0];
                is[i][1]= ni[1];
                flag=false;
                break;
            }
        }
        
        int start= is[0][0], end= is[0][1];
        for(int i=0; i<is.size(); i++){
            if(end>= is[i][0]){
                end= max(is[i][1], end);
                start= min(is[i][0], start);
            }else{
                ans.push_back({start, end});
                start= is[i][0];
                end= is[i][1];
            }
        }
        ans.push_back({start, end});
        if(flag){ 
            int idx=ans.size();
            for(int i=0; i<ans.size(); i++){
                if(ans[i][0]>ni[0]){
                    idx=i;
                    break;
                }
            }
            ans.push_back(ni);
            vector<int> t= ans[idx];
            ans[idx]= ni;
            for(int i=idx+1; i<ans.size(); i++){
                vector<int> x= ans[i];
                ans[i]=t;
                t=x;
            }
        }
        return ans;
    }
};