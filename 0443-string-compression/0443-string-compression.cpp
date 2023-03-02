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
                vector<int> v;
                while(cnt>0) {
                    v.push_back(cnt%10);
                    cnt/=10;
                }
                reverse(v.begin(), v.end());
                for(int k=0; k<v.size(); k++){
                    i++;
                    chars[i]= v[k]+'0';
                }
            }
            i++;
            
        }
        return i;
    }
};