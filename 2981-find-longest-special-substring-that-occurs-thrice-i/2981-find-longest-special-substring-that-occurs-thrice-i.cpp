class Solution {
public:
    int maximumLength(string s) {
        vector<map<int, int>> freq(26);
        for(int i=0; i<s.length(); i++){
            char ch= s[i];
            int cnt=0;
            for(int j=i; j<s.length(); j++){
                if(ch==s[j]) cnt++;
                else break;
                freq[ch-'a'][cnt]++;
            }
        }
        int ans=-1;
        for(auto i: freq){
            for(auto itr= i.rbegin(); itr!= i.rend(); itr++){
                if(itr->second>=3){
                    ans= max(ans, itr->first);
                    break;
                }
            }
        }
        return ans;
        // for(auto i: freq){
        //     for(auto j: i){
        //         cout<<j.first<<" "<<j.second<<endl;
        //     }
        //     cout<<"--\n";
        // }
        //return 2;
    }
};