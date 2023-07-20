class Solution {
public:
    vector<int> asteroidCollision(vector<int>& atds) {
        vector<int> res;
        for(int i=0; i<atds.size(); i++){
            if(atds[i]<0){
                bool dest=false;
                while(res.size()>0 && res.back()>0 && -1*atds[i] >= res.back()){
                    if(-1*atds[i]==res.back()){
                        res.pop_back();
                        dest=true;
                        break;
                    }
                    res.pop_back();
                }
                if((res.size()==0 || (res.back()<0)) && !dest) res.push_back(atds[i]); 
            }else{
                res.push_back(atds[i]);
            }
        }
        return res;
    }
};