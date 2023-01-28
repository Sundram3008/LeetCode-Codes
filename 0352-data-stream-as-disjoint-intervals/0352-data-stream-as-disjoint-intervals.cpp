class SummaryRanges {
public:
    multiset<vector<int>> ans;
    SummaryRanges() {
        
    }
    
    
    void addNum(int val) {
        auto it= ans.lower_bound({val, val});
        int start=val, end=val;
        if(it!= ans.begin()){
            auto x= *(--it);
            if(x[1]+1< val) it++;
        }
        while(it!= ans.end() && val >= (*it)[0]-1 && val<= (*it)[1]+1){
            start= min(start, (*it)[0]);
            end= max(end, (*it)[1]);
            it = ans.erase(it);
        }
        ans.insert(it, {start, end});
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */