class Solution {
public:
    bool isValid(vector<vector<char>> &v, int r, int c, int d){
        for(int i=0; i<v[0].size(); i++){
            if(v[r][i]==char(d+'0')) return false;
            if(v[i][c]==char(d+'0')) return false;
            if(v[3* (r/3)+i/3][3*(c/3)+i%3]==char(d+'0')) return false;
        }
        return true;
    }
    bool solver(vector<vector<char>> & v){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(v[i][j]=='.'){
                    for(int d=1; d<=9; d++){
                        if(isValid(v,i,j,d)){
                            v[i][j]= char(d+'0');
                            if(solver(v)) return true;
                            else v[i][j]='.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};