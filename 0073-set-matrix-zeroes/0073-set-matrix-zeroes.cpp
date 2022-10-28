class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<pair<int,int>> vp;
        // for(int i=0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){
        //         if(matrix[i][j]==0) vp.push_back(make_pair(i,j));
        //     }
        // }
        // for(auto i: vp){
        //     for(int j=0; j<matrix[0].size(); j++) matrix[i.first][j]=0;
        //     for(int j=0; j<matrix.size(); j++) matrix[j][i.second]=0;
        // }
        // return;
        //in O(1)
        bool row=false,col=false;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    if(i==0) row=true;
                    if(j==0) col=true;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(row)
            for(int i=0; i<matrix[0].size(); i++) matrix[0][i]=0;
        if(col)
            for(int i=0; i<matrix.size(); i++) matrix[i][0]=0;
        return ;
    }
};