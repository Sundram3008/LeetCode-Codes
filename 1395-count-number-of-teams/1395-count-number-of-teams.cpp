class Solution {
public:
    int numTeams(vector<int>& rating) {
        set<int> st;
        set<int> prevst;
        int res=0;
        
        for(auto i: rating ) st.insert(i);
        for(int i=0; i<rating.size()-1; i++){
            st.erase(rating[i]);
            int cnta=0, cntb=0, icnta=prevst.size(), icntb= st.size();
            for(auto j= prevst.begin(); j!=prevst.end(); j++){
                if(*j>= rating[i]) break;
                cnta++;
            }
            for(auto j= st.rbegin(); j!= st.rend(); j++){
                if(*j<= rating[i]) break;
                cntb++;
            }
            cout<<cnta<<" "<<cntb<<endl;
            icnta-= cnta;
            icntb-= cntb;
            res+= (cnta*cntb);
            res+= (icnta*icntb);
            prevst.insert(rating[i]);
        }
        return res;
    }
};