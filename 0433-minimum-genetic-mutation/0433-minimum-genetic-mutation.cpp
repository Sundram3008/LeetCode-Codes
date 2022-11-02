class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>> q;
        vector<char> choice= {'A', 'C', 'G', 'T'};
        unordered_map<string,bool> mp;
        for(auto i: bank) mp[i]=true;
        q.push({start,0});
        while(!q.empty()){
            string str= q.front().first;
            int moves= q.front().second;
            q.pop();
            if(str==end) return moves;
            for(int i=0; i<8; i++){
                for(int j=0;j<=3; j++){
                    if(choice[j]!=str[i]){
                        string t= str;
                        t[i]= choice[j];
                        if(mp[t]){ 
                            mp[t]=false;
                            q.push({t,moves+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};