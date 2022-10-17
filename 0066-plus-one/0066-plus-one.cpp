class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        vector<int> ans;
        int carry=1;
        for(int i=d.size()-1; i>=0; i--){
            int x= d[i]+carry;
            ans.push_back(x%10);
            carry= x/10;
        }
        while(carry>0){
            ans.push_back(carry%10);
            carry/=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};