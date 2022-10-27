class Solution {
public:
    int countOnes(vector<vector<int>>& img1, vector<vector<int>>& img2, int n, int r, int c){
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i+r)<0 || (j+c)<0 || i+r>=n || j+c>=n) continue;
                if(img1[i+r][j+c]+ img2[i][j] ==2) cnt++; 
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0,n=img1.size();
        for(int i=-n+1; i<n; i++){
            for(int j= -n+1; j<n; j++){
                ans= max(ans,countOnes(img1, img2, n, i, j));
            }
        }
        return ans;
    }
};