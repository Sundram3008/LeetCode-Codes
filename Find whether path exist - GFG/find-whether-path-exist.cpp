//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool help(vector<vector<int>> &grid, int n, int i, int j){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 ) return false;
        if(grid[i][j]==2) return true;
        grid[i][j]=0;
        if(help(grid, n, i+1,j)) return true;
        if(help(grid, n, i, j+1)) return true;
        if(help(grid, n, i-1, j)) return true;
        if(help(grid, n, i, j-1)) return true;
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size(), srcx=0, srcy=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    srcx= i;
                    srcy=j;
                    break;
                }
            }
        }
        return help(grid, n, srcx, srcy);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends