class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        for(int j=0; j<chars.size(); j++){
            char ch= chars[j];
            int cnt=0;
            while(j<chars.size() && chars[j]==ch) j++,cnt++;
            j--;
            chars[i]=ch;
            if(cnt>=2){
                string v= to_string(cnt);
                for(int k=0; k<v.size(); k++){
                    i++;
                    chars[i]= v[k];
                }
            }
            i++;
            
        }
        return i;
    }
};