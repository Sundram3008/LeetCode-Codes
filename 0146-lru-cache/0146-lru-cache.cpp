class dll{
    public :
    int val;
    dll *next;
    dll *prev;
    dll(int data){
        val= data;
        next= NULL;
        prev= NULL;
    }
    dll(int data, dll *node){
        val= data;
        prev= node;
        next=NULL;
    }
};

class LRUCache {
public:
    int cap, tnodes;
    dll *head, *tail, *temp;
    
    unordered_map<int , pair<int, dll*>> datas;
    LRUCache(int capacity) {
        cap=capacity;
        head= new dll(-1);
        tail= head;
        temp=head;
        tnodes=0;
    }
    
    void deleteNode(int key){
        dll *node= datas[key].second;
        dll *pnode = node->prev;
        dll *nnode = node->next;
        pnode->next= nnode;
        nnode->prev= pnode;
        delete node;
    }
    int get(int key) {
        
        if(datas.find(key)==datas.end()) return -1;
        int val= datas[key].first;
        tail->next = new dll(key, tail);
        tail= tail->next;
        deleteNode(key);
        datas[key].second= tail;
        return val;
    }
    void put(int key, int value) {
        
        tnodes++;
        tail->next = new dll(key, tail);
        tail= tail->next;
        if(datas.find(key)!=datas.end()){
            deleteNode(key);
            tnodes--;
        }else{
            if(tnodes>cap){
                int x= temp->next->val;
                deleteNode(x);
                datas.erase(x);
                tnodes--;
            }
        }
        
        datas[key]= {value, tail};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */