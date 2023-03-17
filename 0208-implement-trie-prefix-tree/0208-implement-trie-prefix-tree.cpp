class Trie {
public:
    vector<Trie*> chars;
    bool isEnd=false;
    Trie() {
        for(int i=0; i<26; i++) chars.push_back(NULL);
        isEnd=false;
    }
    
    void insert(string word) {
        Trie *temp= this;
        for(auto i: word){
            if(temp->chars[i-'a']==NULL){
                temp->chars[i-'a']= new Trie();
            }
            temp= temp->chars[i-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        Trie *temp= this;
        for(auto i: word){
            if(temp->chars[i-'a']==NULL) return false;
            temp= temp->chars[i-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* temp= this;
        for(auto i: prefix){
            if(temp->chars[i-'a']==NULL) return false;
            temp= temp->chars[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */