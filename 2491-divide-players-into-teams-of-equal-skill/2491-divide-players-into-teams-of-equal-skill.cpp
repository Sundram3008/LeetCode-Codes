class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int l=1, r= skill.size()-2;
        long long int ans=skill[0]*skill.back(), prev=0;
        prev=skill[0]+skill.back();
        while(l<r){
            if(skill[l]+skill[r]!=prev) return -1;
            else ans= ans+ (skill[l]*skill[r]);
            l++,r--;
        }
        return ans;
    }
};