class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0; i<words.size(); i++){
            vector<bool> c1(26,false);
            for(int j=0; j<words[i].size(); j++) c1[words[i][j]-'a']=true;
            for(int j=i+1; j<words.size(); j++){
                vector<bool> c2(26,false);
                for(int k=0; k<words[j].size(); k++) c2[words[j][k]-'a']=true;
                if(c1==c2) cnt++;
            }
        }
        return cnt;
    }
};