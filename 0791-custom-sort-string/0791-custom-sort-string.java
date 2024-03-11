class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> priors(26, INT_MAX);
        for(int i=0; i<order.length(); i++) priors[order[i]-'a']=i;
        sort(s.begin(), s.end(), [&](char a, char b){
            return priors[a-'a'] < priors[b-'a'];
        });
        return s;
    }
};