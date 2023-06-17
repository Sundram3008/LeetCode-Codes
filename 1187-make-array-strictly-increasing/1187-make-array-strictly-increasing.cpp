class Solution {
public:
    int check(int curr, int left, vector<int> &arr1, vector<int> &arr2, vector<unordered_map<int,int>> &dp){
        if(curr == arr1.size()) return 0;
        if(dp[curr].find(left) != dp[curr].end()) return dp[curr][left];
        int res1, res2;
        if(arr1[curr]> left) res1 = check(curr+1, arr1[curr], arr1, arr2, dp);
        else res1=INT_MAX;
        int rep= upper_bound(arr2.begin(), arr2.end(), left)- arr2.begin();
        if(rep== arr2.size()) res2= INT_MAX;
        else res2= check(curr+1, arr2[rep], arr1, arr2, dp);
        if(res2==INT_MAX) dp[curr][left]=res1;
        else dp[curr][left]= min(res1, res2+1);
        return dp[curr][left];
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n= arr1.size();
        vector<unordered_map<int,int>> dp(n+1);
        int val= check(0, INT_MIN, arr1, arr2, dp);
        return (val!=INT_MAX)?val:-1;
    }
};