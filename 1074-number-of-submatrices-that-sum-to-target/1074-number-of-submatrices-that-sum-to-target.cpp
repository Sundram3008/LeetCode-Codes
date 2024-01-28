class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r= matrix.size(), c= matrix[0].size();
        for(int i=0; i<r; i++){
            for(int j=1; j<c; j++){
                matrix[i][j]+= matrix[i][j-1];
            }
        }
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0; i<c; i++){
            for(int j=i; j<c; j++){
                
                int sum=0;
                mp={{0,1}};
                for(int k=0; k<r; k++){
                    sum+= matrix[k][j]- ((i>0)? matrix[k][i-1]:0);
                    if(mp.find(sum-target)!=mp.end()) ans+= mp[sum-target];
                    else ans+=0;
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};