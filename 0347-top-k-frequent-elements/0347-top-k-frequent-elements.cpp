class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, unordered_map<int,bool>> mp;
//         unordered_map<int,int> cnts;
//         int maxcnt=0;
//         for(int i=0; i<nums.size(); i++){
//             cnts[nums[i]]++;
//             int x= cnts[nums[i]]-1;
//             mp[x].erase(nums[i]);
//             mp[x+1][nums[i]]=true;
//             maxcnt= max(maxcnt, x+1);
//         }
//         vector<int> ans;
//         while(k>0){
//             for(auto i: mp[maxcnt]){
//                 ans.push_back(i.first);
//                 k--;
//                 if(k==0) return ans;
//             }
//             maxcnt--;
//         }
        
//         return ans;
        unordered_map<int,int>mp;
        for(auto i: nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i= mp.begin(); i!= mp.end(); i++){
            pq.push(make_pair(i->second,i->first));
        }
        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        

    }
    
    
};