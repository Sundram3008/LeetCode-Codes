class MagicDictionary {
public:
    unordered_map<int,vector<string>> strs;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto dict: dictionary)
        strs[dict.size()].push_back(dict);
    }
    
    bool search(string sw) {
        for(auto i: strs[sw.size()]){
            int f=0, s=0, cnt=0;
            while(f<i.size() && s<sw.size()){
                if(i[f]!= sw[s]){
                    cnt++;
                }
                if(cnt==2) break;
                f++, s++;
            }
            
            
            if(f==i.size() && s==sw.size() && cnt==1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */