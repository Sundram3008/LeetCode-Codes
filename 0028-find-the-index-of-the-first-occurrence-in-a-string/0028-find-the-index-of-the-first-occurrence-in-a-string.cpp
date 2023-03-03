class Solution {
public:
    int strStr(string haystack, string needle) {
        // use kmp
        int j=haystack.find(needle);
        return j;
    }
};