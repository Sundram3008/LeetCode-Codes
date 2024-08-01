class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(auto &i: details){
            int age=( i[11]-'0')*10 + i[12]- '0';
            if(age>60) res++;
        }
        return res;
    }
};