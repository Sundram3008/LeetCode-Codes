class Solution {
public:
    
    // int dfs(int idx, string &s, string &temp, vector<vector<int>> &v, unordered_map<string, int> &dp){
    //     if(idx>=s.size()){
    //         return 0;
    //     }
    //     if(dp.find(temp)!= dp.end()) return dp[temp];
    //     char ch= s[idx];
    //     int val=INT_MAX;
    //     string x=temp;
    //     for(auto i: v[ch-'a']){
    //         if(i>= idx){
    //             for(int j=idx; j<=i; j++){
    //                 temp[j]=ch;
    //             }
    //             val= min(dfs(idx+1, s, temp, v, dp), val);
    //         }
    //     }
    //     temp=x;
    //     if(temp[idx]!= ch) val++;
    //     dp[temp]=val;
    //     return val;
    // }
    int strangePrinter(string s) {
        // int n=s.length();
        // string str;
        // str.append(n, '#');
        // vector<vector<int>> v(26);
        // int l=0;
        // for(int i=0; i<s.length(); i++){
        //     char ch= s[i];
        //     while(i<s.length() && s[i]==ch){
        //         i++;
        //     }
        //     v[ch-'a'].push_back(i-1);
        //     i--;
        // }
        // unordered_map<string, int> dp;
        // //cout<<str<<endl;
        // //return 0;
        // return dfs(0, s, str, v, dp);
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + 1;
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + (k+1<=j-1 ? dp[k+1][j-1] : 0));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    
    
};