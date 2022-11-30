class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1, mp2;
        for(int i=0; i<arr.size(); i++) mp1[arr[i]]++;
        for(auto i: mp1){
            mp2[i.second]++;
            if(mp2[i.second]>1) return false;
        }
        return true;
    }
};