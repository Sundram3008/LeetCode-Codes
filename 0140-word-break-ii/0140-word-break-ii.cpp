class Solution {
public:
    vector<vector<string>> wordsStream;
    void partitions(int idx, int n, string &s, unordered_map<string, bool> &words, vector<string> &temp){
        if(idx==n){
            wordsStream.push_back(temp);
            return;
        }
        string word="";
        for(int i=idx; i<n; i++){
            word.push_back(s[i]);
            if(words[word]){
                temp.push_back(word);
                partitions(i+1, n, s, words, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences, tempWords;
        unordered_map<string, bool> dict;
        for(auto &i: wordDict) dict[i]=true;
        partitions(0, s.length(), s, dict, tempWords);
        for(auto &i: wordsStream){
            string temp;
            for(auto &j: i){
                temp+= j+" ";
            }
            temp.pop_back();
            sentences.push_back(temp);
        }
        return sentences;
    }
};