class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int> q;
        vector<bool> vis(arr.size(), false);
        unordered_map<int,vector<int>> same;
        for(int i=0; i<arr.size(); i++){
            same[arr[i]].push_back(i);
        }
        int steps=0;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                int idx= q.front();
                q.pop();
                if(idx== arr.size()-1 ) return steps;
                for(int j=0; j<same[arr[idx]].size(); j++){
                    if(!vis[same[arr[idx]][j]]){
                        q.push(same[arr[idx]][j]);
                        vis[same[arr[idx]][j]]=true;
                    }
                }
                same[arr[idx]].clear();
                if(idx-1>=0 && !vis[idx-1]){
                    q.push(idx-1);
                    vis[idx-1]=true;
                }
                if(idx+1< arr.size() && !vis[idx+1]){
                    q.push(idx+1);
                    vis[idx+1]=true;
                }
            }
            steps++;
        }
        return steps;
    }
};