class Solution {
public:
    
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int ans=0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=true;
        for(int i=0; i<nums.size(); i++){
            int x= nums[i], cnt=1;
            while(mp[sqrt(x)]){
                int p= sqrt(x);
                if(p*p==x) cnt++;
                else break;
                mp[p]=false;
                x= p;
            }
            ans= max(ans, cnt);
        }
        return (ans>=2)? ans:-1;
    }
};