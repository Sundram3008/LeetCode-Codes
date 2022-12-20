class Allocator {
public:
    vector<int> mem;
    Allocator(int n) {
        vector<int> v(n,0);
        mem=v;
    }
    
    int allocate(int size, int mID) {
        int curr=0, s=0;
        bool flag=false;
        for(int i=0; i<mem.size() && (!flag); i++){
            if(mem[i]==0) curr++;
            else{
                if(curr>=size){
                    for(int j=s; j<= i; j++){
                        mem[j]= mID;
                    }
                    flag=true;
                }else{ 
                    s=i+1;
                    curr=0;
                }
            }
            if(curr>=size){
                    for(int j=s; j<= i; j++){
                        mem[j]= mID;
                    }
                    flag=true;
            }
        }
        if(flag) return s;
        else return -1;
    }
    
    int free(int mID) {
        int cnt=0;
        for(int i=0; i<mem.size(); i++) if(mem[i]==mID) mem[i]=0, cnt++;
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */