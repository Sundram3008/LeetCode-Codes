class MyQueue {
public:
    stack<int> inp, out;
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        peek();
        int x= out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if(out.empty()){
            while(inp.size()){
                out.push(inp.top());
                inp.pop();
            }        
        }
        return out.top();
    }
    
    bool empty() {
        return inp.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */