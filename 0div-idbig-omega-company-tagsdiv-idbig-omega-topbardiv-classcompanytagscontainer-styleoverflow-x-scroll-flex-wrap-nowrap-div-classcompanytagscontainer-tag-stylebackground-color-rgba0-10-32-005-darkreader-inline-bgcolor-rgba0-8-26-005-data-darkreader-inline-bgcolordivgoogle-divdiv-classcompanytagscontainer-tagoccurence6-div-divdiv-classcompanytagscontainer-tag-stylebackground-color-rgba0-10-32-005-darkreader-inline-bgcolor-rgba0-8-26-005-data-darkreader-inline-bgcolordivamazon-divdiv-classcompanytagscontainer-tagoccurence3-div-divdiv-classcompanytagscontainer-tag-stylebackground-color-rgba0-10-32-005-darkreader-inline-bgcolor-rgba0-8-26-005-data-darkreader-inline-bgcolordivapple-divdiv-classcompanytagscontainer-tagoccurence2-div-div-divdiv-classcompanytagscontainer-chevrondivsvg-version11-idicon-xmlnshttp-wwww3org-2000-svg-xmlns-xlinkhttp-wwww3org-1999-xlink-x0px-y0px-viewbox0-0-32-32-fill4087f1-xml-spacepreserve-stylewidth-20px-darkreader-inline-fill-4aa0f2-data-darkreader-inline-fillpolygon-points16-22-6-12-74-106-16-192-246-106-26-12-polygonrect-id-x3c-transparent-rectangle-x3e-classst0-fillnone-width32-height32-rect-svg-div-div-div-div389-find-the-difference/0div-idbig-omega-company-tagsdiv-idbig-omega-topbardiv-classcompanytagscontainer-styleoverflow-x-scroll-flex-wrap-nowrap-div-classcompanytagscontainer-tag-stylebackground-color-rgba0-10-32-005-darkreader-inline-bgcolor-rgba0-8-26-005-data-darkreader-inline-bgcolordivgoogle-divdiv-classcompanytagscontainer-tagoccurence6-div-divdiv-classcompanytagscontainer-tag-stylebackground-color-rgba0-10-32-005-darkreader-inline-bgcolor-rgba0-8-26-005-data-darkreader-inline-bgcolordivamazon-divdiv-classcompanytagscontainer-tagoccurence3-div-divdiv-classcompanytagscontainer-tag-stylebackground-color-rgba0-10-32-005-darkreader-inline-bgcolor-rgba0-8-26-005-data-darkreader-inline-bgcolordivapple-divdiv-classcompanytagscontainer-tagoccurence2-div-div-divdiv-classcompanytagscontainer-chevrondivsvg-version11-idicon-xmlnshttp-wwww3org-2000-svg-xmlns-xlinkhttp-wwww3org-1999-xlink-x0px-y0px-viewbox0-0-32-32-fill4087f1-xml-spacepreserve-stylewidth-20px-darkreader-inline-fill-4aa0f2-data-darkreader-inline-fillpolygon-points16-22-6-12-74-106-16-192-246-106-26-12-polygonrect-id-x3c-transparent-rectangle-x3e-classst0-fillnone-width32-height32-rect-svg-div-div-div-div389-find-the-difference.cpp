class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(char i: s) freq[i-'a']++;
        for(char i: t) freq[i-'a']--;
        for(int i=0; i<26; i++)
            if(freq[i]==-1) return i+'a'; 
        return 'a';
    }
};