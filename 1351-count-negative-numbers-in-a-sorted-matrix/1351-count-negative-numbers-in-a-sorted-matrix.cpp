class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r= grid.size(), c= grid[0].size(), i=c-1, j=0, ans=0;
        while(i>=0 && j<r){
            if(grid[j][i]<0) i--;
            else{
                ans+= (c-i-1);
                j++;
            }
        }
        ans+= ((c-i-1)*(r-j));
        return ans;
    }
};