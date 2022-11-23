class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0}, cols[9][9]= {0}, mat[9][9]={0};
        for(int i=0; i< board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!='.'){
                    int num= board[i][j]-'0' -1, k= i/3 *3 + j/3;
                    if(rows[i][num] || cols[j][num] || mat[k][num]) return false;
                    rows[i][num]= cols[j][num]= mat[k][num]=1;
                }
            }
        }
        return true;
    }
};