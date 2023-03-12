class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt=0;
        for(int i=left; i<= right; i++){
            cnt+= (isVowel(words[i][0]) && isVowel(words[i].back()));
        }
        return cnt;
    }
};