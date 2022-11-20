class Solution {
public:
    int calculate(string s) {
        vector<int> signs{1,1};
        int number = 0;
        int total = 0;
        int curSign = 1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(isdigit(c)){
                while(i < s.size() && isdigit(s[i]) ){
                    number = number*10 + (s[i] - '0');
                    i++;
                }
                total += number * curSign;
                number = 0;
                i--;
            }else if(c == ')'){
                signs.pop_back();
            }else if(c == '+' || c == '-'){
                curSign = signs.back() * ( c == '-'? -1 : 1);
            }else if(c == '('){
                signs.push_back(curSign);
            }
        }
        return total;
    }
};