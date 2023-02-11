class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> graph(n);
        map<vector<int>, char>mp;
        map<string,bool> vis;
        for(auto i: redEdges){
            graph[i[0]].push_back(i[1]);
            mp[{i[0],i[1],'r'}]='r';
        }
        for(auto i: blueEdges){
            graph[i[0]].push_back(i[1]);
            mp[{i[0],i[1],'b'}]='b';
        }
        queue<pair<int,char>> q;
        vector<int> ans(n,-1);
        q.push({0,'?'});
        int dist=0;
        ans[0]=0;
        while(!q.empty()){
            int x= q.size();
            for(int i=0; i<x; i++){
                int idx= q.front().first;
                char prev= q.front().second;
                q.pop();
                for(auto j: graph[idx]){
                    string s;
                    s.push_back(char(idx));
                    s.push_back(' ');
                    s.push_back(char(j));
                    s.push_back(' ');
                    if(mp.find({idx,j,'r'})!=mp.end()){
                        s.push_back(mp[{idx,j,'r'}]);
                        if(vis.find(s)==vis.end() && mp[{idx,j,'r'}]!=prev){
                            q.push({j, mp[{idx,j,'r'}]});
                            if(ans[j] == -1) ans[j] = dist+1;
                            ans[j]= min(ans[j], dist+1);
                            vis[s]=true;
                        }
                    }
                    if(s.back()=='r') s.pop_back();
                    if(mp.find({idx,j,'b'})!=mp.end()){
                        s.push_back(mp[{idx,j,'b'}]);
                        if(vis.find(s)==vis.end() && mp[{idx,j,'b'}]!=prev){
                            q.push({j, mp[{idx,j,'b'}]});
                            if(ans[j] == -1) ans[j] = dist+1;
                            ans[j]= min(ans[j], dist+1);
                            vis[s]=true;
                        }
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};