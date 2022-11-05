class Trie{
    public:
    Trie *child[26];
    bool isEnd;
    Trie(){
        for(int i=0; i<26; i++) child[i]= NULL;
        isEnd=false;
    }
};
void addWord(Trie *node, string str){
    for(int i=0; i<str.size(); i++){
        if(node->child[str[i]-'a']==NULL)
            node->child[str[i]-'a']= new Trie();
        node= node->child[str[i]-'a'];
    }
    node->isEnd=true;
}
class Solution {
public:
    vector<string> ans;
    void dfs(vector<vector<char>> &board, int i, int j, string str, Trie* node){
        int r= board.size(), c= board[0].size();
        if(board[i][j]=='T'|| node==NULL || node->child[board[i][j]-'a']==NULL) return;
        char x=board[i][j];
        str.push_back(x);
        node= node->child[x-'a'];
        if(node->isEnd==true){
            ans.push_back(str);
            node->isEnd=false;
        }
        board[i][j]='T';
        if(i<r-1) dfs(board, i+1,j, str, node);
        if(j<c-1) dfs(board, i, j+1, str, node);
        if(i-1>=0) dfs(board, i-1, j, str, node);
        if(j-1>=0) dfs(board, i, j-1, str, node);
        str.pop_back();
        board[i][j]=x;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie * node= new Trie();
        for(auto i: words) addWord(node, i);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, i, j, "", node);
            }
        }
        return ans;
    }
};