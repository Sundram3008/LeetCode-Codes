class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans=0;
        for(int i=0; i<strs.size(); i++){
            int j=0, val=0;
            for(j=0; j<strs[i].size(); j++){
                if(strs[i][j]>='0' && strs[i][j]<='9'){
                    val*=10;
                    val+= strs[i][j]-'0';
                }else break;
            }
            if(j==strs[i].size()) ans= max(ans, val);
            else ans= max(ans, (int)strs[i].size());
        }
        return ans;
    }
};