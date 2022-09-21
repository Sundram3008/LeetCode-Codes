class Trie{
    public:
    Trie* child[26];
    bool isEnd;
    int cnt;
    Trie(){
        for(int i=0; i<26; i++) child[i]=NULL;
        isEnd=false;
        cnt=0;
    }
};
void insert(Trie* root,string word) {
        Trie *temp= root;
        for(int i=0; i<word.size(); i++){
            int idx= word[i]-'a';
            if(temp->child[idx]==NULL)
                temp->child[idx]= new Trie();
            temp= temp->child[idx];
            temp->cnt++;
        }
        temp->isEnd=true;
}
    
int search(Trie *root,string word) {
        Trie *temp= root;
        int val=0;
        for(int i=0; i<word.size(); i++){
            int idx= word[i]-'a';
            temp= temp->child[idx];
            val+=temp->cnt;
        }
        return val;
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root= new Trie();
        for(auto i: words){
            insert(root,i);
        }
        vector<int> ans;
        for(auto i: words){
            ans.push_back(search(root, i));
        }
        return ans;
    }
};