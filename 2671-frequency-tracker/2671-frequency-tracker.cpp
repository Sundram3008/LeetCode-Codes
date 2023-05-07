class FrequencyTracker {
public:
    unordered_map<int,int> mp, mp2;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        mp[number]++;
        mp2[mp[number]]++;
        mp2[mp[number]-1]--;
    }
    
    void deleteOne(int number) {
        if(mp[number]>0){
            mp[number]--;
            mp2[mp[number]]++;
            mp2[mp[number]+1]--;
        }
    }
    
    bool hasFrequency(int frequency) {
        return mp2[frequency]>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */