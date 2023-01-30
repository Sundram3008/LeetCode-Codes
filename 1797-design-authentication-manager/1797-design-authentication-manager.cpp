class AuthenticationManager {
public:
    long period;
    unordered_map<string, long> mp1;
    map<long, string> mp2;
    AuthenticationManager(int timeToLive) {
        period= timeToLive;
    }
    
    void expire(int currentTime){
        for(auto i: mp2){
            if(i.first<= currentTime){
                mp1.erase(i.second);
                mp2.erase(i.first);
            }
            else break;
        }
        return;
    }
    void generate(string tokenId, int currentTime) {
        expire(currentTime);
        mp1[tokenId]= currentTime+ period;
        mp2[currentTime+period]= tokenId;
    }
    
    void renew(string tokenId, int currentTime) {
        expire(currentTime);
        if(mp1.find(tokenId)!= mp1.end()){
            mp2.erase(mp1[tokenId]);
            mp1[tokenId] = currentTime+ period;
            mp2[currentTime+period]= tokenId;
        }
        return ;
    }
    
    int countUnexpiredTokens(int currentTime) {
        expire(currentTime);
        return mp2.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */