class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q1, q2;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='R') q1.push(i);
            else q2.push(i);
        }
        while(!q1.empty() && (!q2.empty())){
            int x= q1.front(), y= q2.front();
            q1.pop();
            q2.pop();
            if(x<y){
                q1.push(x+s.size());
            }else{
                q2.push(y+s.size());
            }
        }
        if(q1.empty()) return "Dire";
        else return "Radiant";
    }
};