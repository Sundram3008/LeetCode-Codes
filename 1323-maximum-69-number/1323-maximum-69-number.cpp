class Solution {
public:
    int maximum69Number (int num) {
        string k=to_string(num);
        auto x=k.find('6');
        if(x!=string::npos) k[x]='9';
        num=stoi(k);
        return num;
    }
};