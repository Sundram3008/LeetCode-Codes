class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto &i: letters){
            if(target<i) return i;
        }
        return  letters[0];
    }
};