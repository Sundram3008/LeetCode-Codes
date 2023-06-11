class SnapshotArray {
public:
    unordered_map<int, map<int,int>> mp;
    int snaps=0;
    SnapshotArray(int length) {
        for(int i=0; i<length; i++) {
            map<int,int> temp;
            temp[0]=0;
            mp[i]=temp;
        }
    }
    
    void set(int index, int val) {
        mp[index][snaps]=val;
    }
    
    int snap() {
        return snaps++;
    }
    
    int get(int index, int snap_id) {
        auto temp= mp[index].upper_bound(snap_id);
        temp--;
        return temp->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */