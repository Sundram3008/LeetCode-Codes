class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int r= grid.size(), c= grid[0].size();
        vector<int> ans;
        for(int j=0; j<c; j++){
            int m=0;
            for(int i=0; i<r; i++){
                int x= grid[i][j], cnt=0;
                if(x<=0) cnt++;
                x= abs(x);
                while(x>0){
                    x/=10;
                    cnt++;
                }
                m= max(m, cnt);
            }
            ans.push_back(m);
        }
        return ans;
    }
};