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
                char ori= str[i];
                for(int j=0;j<=3; j++){
                    if(choice[j]!=str[i]){
                        str[i]= choice[j];
                        if(mp[str]){ 
                            mp[str]=false;
                            q.push({str,moves+1});
                        }
                    }
                    str[i]=ori;
                }
            }
        }
        return -1;
    }
};