class MedianFinder {
public:
    priority_queue<int> lowers;
    priority_queue<int, vector<int>, greater<int>> uppers;
    MedianFinder() {
        uppers.push(INT_MAX);
        lowers.push(INT_MIN);
    }
    
    void addNum(int num) {
        if(num<= uppers.top()) lowers.push(num);
        else uppers.push(num);
        if(lowers.size()> uppers.size()+1){
            uppers.push(lowers.top());
            lowers.pop();
        }else if(lowers.size()+1< uppers.size()){
            lowers.push(uppers.top());
            uppers.pop();
        }
    }
    
    double findMedian() {
        if(lowers.size()==uppers.size()){
            return (lowers.top()+uppers.top())*1.0/2;
        }else if(lowers.size()>uppers.size()){
            return double(lowers.top());
        }else return double(uppers.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */