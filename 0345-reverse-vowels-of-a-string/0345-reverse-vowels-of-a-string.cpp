class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> mp;
        mp['a']=true, mp['A']=true;
        mp['e']=true, mp['E']=true;
        mp['i']=true, mp['I']=true;
        mp['o']=true, mp['O']=true;
        mp['u']=true, mp['U']=true;
        int l=0,r=s.length()-1;
        while(l<r){
            if(mp[s[l]] && mp[s[r]]){
                swap(s[l], s[r]);
                l++,r--;
            }else if(mp[s[l]]) r--;
            else if(mp[s[r]])l++;
            else l++,r--;
        }
        return s;
    }
};