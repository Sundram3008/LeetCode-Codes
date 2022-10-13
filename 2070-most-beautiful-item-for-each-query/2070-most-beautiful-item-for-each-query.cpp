class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int>mp;
        set<int> st;
        st.insert(-1);
        mp[-1]=0;
        for(auto i: items){
            if(mp.find(i[0])!=mp.end()){
                if(mp[i[0]]<i[1])
                    mp[i[0]]=i[1];
            }
            else{ mp[i[0]]=i[1];}
            st.insert(i[0]);
        }
        int val= mp.begin()->second;
        for(auto && [first,second]: mp){
            if(second<val) second=val;
            else val= second;
        }
        vector<int> ans;
        for(auto i: queries){
            if(mp.find(i)!=mp.end()){
                ans.push_back(mp[i]);
            }else{
                auto x= --st.upper_bound(i);
                ans.push_back(mp[*x]);
            }
        }
        //cout<<(++mp.begin())->first;
        return ans;
    }
};