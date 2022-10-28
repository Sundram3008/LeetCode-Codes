class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vp;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0) vp.push_back(make_pair(i,j));
            }
        }
        for(auto i: vp){
            for(int j=0; j<matrix[0].size(); j++) matrix[i.first][j]=0;
            for(int j=0; j<matrix.size(); j++) matrix[j][i.second]=0;
        }
        return;
    }
};