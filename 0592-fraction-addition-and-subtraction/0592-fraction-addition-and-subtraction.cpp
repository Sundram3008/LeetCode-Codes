class Solution {
public:
    string fractionAddition(string exp) {
        int idx=1;
        if(exp[0]!='-') exp.insert(0, "+");
        exp.push_back('+');
        int n= exp.length();
        int lcm=-1;
        bool take=false;
        int curr=0;
        vector<int> denos;
        while(idx<n){
            if(exp[idx]=='/') take=true;
            else if(exp[idx]=='+' || exp[idx]=='-'){
                take=false;
                if(lcm==-1) lcm=curr;
                lcm= ((lcm/__gcd(lcm, curr))*curr);
                denos.push_back(curr);
                curr=0;
            }else if(take){
                curr= curr*10 + (exp[idx]-'0');
            }
            idx++;
        }
        // got the lcm 
        idx=0;
        take=false;
        int num=0, i=0;
        curr=0;
        bool neg=false;
        while(idx<n){
            
            if(exp[idx]=='+' || exp[idx]=='-'){ 
                take=true;
                if(exp[idx]=='-') neg=true;
                else neg=false;
            }
            else if(exp[idx]=='/') {
                take=false;
                int val= curr*(lcm/ denos[i++]);
                if(neg) val*=-1;
                num+= val;
                curr=0;
            }else if(take){
                curr= curr*10 + (exp[idx]-'0');
            }
            idx++;
        }
        
        int comm= __gcd(num, lcm);
        num/= comm;
        lcm/= comm;
        if(lcm<0) num*=-1;
        return to_string(num)+"/"+ to_string(abs(lcm));
        
    }
};