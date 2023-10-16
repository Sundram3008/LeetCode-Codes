class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int> ans;
        // if(rowIndex==0) return {1};
        // if(rowIndex==1) return {1,1};
        // ans= {1,1};
        // for(int i=2; i<=rowIndex; i++){
        //     vector<int> temp;
        //     temp.push_back(1);
        //     for(int j=1; j<ans.size(); j++){
        //         temp.push_back(ans[j-1]+ans[j]);
        //     }
        //     temp.push_back(1);
        //     ans= temp;
        // }
        // return ans;
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};