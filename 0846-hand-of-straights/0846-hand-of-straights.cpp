class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        map<int,int> mp;
        for(auto i: nums) mp[i]++;
        while(!mp.empty()){
            int x= mp.begin()->first;
            for(int i=0; i<k; i++){
                if(mp.find(x)==mp.end()){
                    return false;
                }
                else {
                    mp[x]--;
                }
                if(mp[x]==0){
                    mp.erase(x);
                }
                x++;
            }
        }
        return true;
    }
};