class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0, b=0, ca=0, cb=0; 
        for(int i=0; i<colors.length(); i++){
            if(colors[i]=='A'){
                if(a==2) ca++;
                else a++;
                b=0;
            }else{
                if(b==2) cb++;
                else b++;
                a=0;
            }
        }
        return (ca>cb);
    }
};