class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int ans=0, curr=0;
        vector<int> val(26,0);
        iota(val.begin(), val.end(), 1); // mapping every character, value val = {1,2,.....,26} size = 26
        for(int i=0; i<chars.size(); i++){
            val[chars[i]-'a']=vals[i];  // changing values of character whose values are given in vals
        }
        for(int i=0; i<s.size(); i++){
            curr+= val[s[i]-'a'];  // vals[s[i]-'a' finds value off that element and further approach follows typical Kadane's algorithm
            if(curr>ans){
                ans= curr;
            }
            if(curr<=0) curr=0;
        }
        return ans; // return ans;
    }
};