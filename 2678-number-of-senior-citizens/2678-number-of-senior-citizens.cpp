class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(auto i: details){
            int age= stoi(i.substr(11));
            age/=100;
            if(age>60) res++;
        }
        return res;
    }
};