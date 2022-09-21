class Trie {
public:
    Trie *child[26];
    bool isEnd;
    Trie() {
        for(int  i=0; i<26; i++) child[i]=NULL;
        isEnd=false;
    }
    
    void insert(string word) {
        Trie *temp= this;
        for(int i=0; i<word.size(); i++){
            int idx= word[i]-'a';
            if(temp->child[idx]==NULL)
                temp->child[idx]= new Trie();
            temp= temp->child[idx];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        Trie *temp= this;
        for(int i=0; i<word.size(); i++){
            int idx= word[i]-'a';
            if(temp->child[idx]==NULL)
                return false;
            temp= temp->child[idx];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *temp= this;
        for(int i=0; i<prefix.size(); i++){
            int idx= prefix[i]-'a';
            if(temp->child[idx]==NULL)
                return false;
            temp= temp->child[idx];
        }
        return true;
        int cnt=0;
        for(int i=0; i<26; i++){
            if(temp->child[i]!=NULL){
                cnt++;    
            }
        }
        return (cnt>0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */