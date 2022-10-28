class Solution {
public:
    bool flag=false;
    void dfs(vector<vector<char>> &board, string word,int r, int c, int i){
        if(i==word.size()){
            flag=true;
            return;
        }
        if(flag || r<0 || c<0 || r>=board.size() || c>= board[0].size() || board[r][c]!= word[i] || board[r][c]=='!') return;
        if(board[r][c]==word[i]){
            char ch= board[r][c];
            board[r][c]='!';
            dfs(board, word, r, c+1, i+1);
            dfs(board, word, r, c-1, i+1);
            dfs(board, word, r+1, c, i+1);
            dfs(board, word, r-1, c, i+1);
            board[r][c]=ch;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    dfs(board, word, i, j, 0);
                }
                if(flag==true) return true;
            }
        }
        return false;
    }
};