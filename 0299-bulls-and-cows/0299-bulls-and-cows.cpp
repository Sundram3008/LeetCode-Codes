class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0, cow=0;
        unordered_map<char,int> mp;
        for(int i=0; i< secret.size(); i++){
            if(secret[i]==guess[i]){
                guess[i]='g';
                bull++;
            }else mp[secret[i]]++;
        }
        for(int i=0; i<guess.size(); i++){
            if(guess[i]!= 'g'){
                if(mp[guess[i]]>0){
                    mp[guess[i]]--;
                    cow++;
                }
            }
        }
        return to_string(bull)+"A"+ to_string(cow)+ "B";
    }
};