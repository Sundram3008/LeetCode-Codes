class Solution {
public:
    string pushDominoes(string dominoes) {
        int i=0;
        string ans="";
        dominoes= 'L'+dominoes+'R';
        for(int j=1; j<dominoes.size(); j++){
            if(dominoes[j]=='.') continue;
            int x=j-i-1;
            if(i>0) ans+=dominoes[i];
            if(dominoes[i]==dominoes[j]) ans+= string(x,dominoes[j]);
            else if(dominoes[i]=='L' && dominoes[j]=='R'){
                ans+= string(x,'.');
            }else{
                ans+= string(x/2,'R')+string(x%2,'.')+string(x/2,'L');
            }
            i=j;
        }
        return ans;
    }
};