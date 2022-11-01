class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // Little hard to understand
        // vector<int> ans(grid[0].size(),-1);
        // map<pair<int,int>,vector<int>> mp;
        // for(int i=0; i<grid[0].size(); i++){
        //     pair<int,int> x(0,i);
        //     mp[x].push_back(i);
        // }
        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid[0].size(); j++){
        //         pair<int,int> x(i,j);
        //         auto v=mp[x];
        //         if(v.size()==1){
        //             //cout<<x.first<<" "<<x.second<<endl;
        //             if(grid[i][j]==1){
        //                 pair<int,int> t(i+1,j+1);
        //                 if(i!=grid.size()-1 && j+1 >=0 && j+1<ans.size() && grid[i][j] == grid[i][j+1])
        //                     mp[t].push_back(v[0]);
        //                 else{
        //                    if(j+1 >=0 && j+1<ans.size() && grid[i][j] == grid[i][j+1]) ans[v[0]]=j+1;
        //                 }
        //             }else{
        //                 pair<int,int> t(i+1,j-1);
        //                 if(i<grid.size()-1 && j-1>=0 && j-1<ans.size() && grid[i][j]==grid[i][j-1])
        //                     mp[t].push_back(v[0]);
        //                 else{
        //                     if(j-1>=0 && j-1<ans.size() && grid[i][j]==grid[i][j-1]) ans[v[0]]=j-1;
        //                 }
        //             }
        //         }
        //         mp.erase(x);
        //     }
        // }
        // return ans;
        int r=grid.size(), c= grid[0].size();
        vector<int> ans(c,-1);
        for(int i=0; i<c; i++){
            int ccol=i, ncol=-1;
            for(int j=0; j<r; j++){
                ncol= ccol+ grid[j][ccol];
                if(ncol<0 || ncol>=c || grid[j][ccol]!=grid[j][ncol]){
                    ccol=-1;
                    break;
                }
                ccol=ncol;
            }
            ans[i]=ccol;
        }
        return ans;
    }
};