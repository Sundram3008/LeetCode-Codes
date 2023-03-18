class BrowserHistory {
public:
    
    vector<string> str;
    int idx=0;
    BrowserHistory(string homepage) {
        str.push_back(homepage);
    }
    
    void visit(string url) {
        if(idx+1!= str.size()){
            while(str.size()>idx+1) str.pop_back();
        }
        str.push_back(url);
        idx++;
    }
    
    string back(int steps) {
        idx= max(0, idx-steps);
        return str[idx];
    }
    
    string forward(int steps) {
        idx= min((int)str.size()-1, idx+steps);
        return str[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */