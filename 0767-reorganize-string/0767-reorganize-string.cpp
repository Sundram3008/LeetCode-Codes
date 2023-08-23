#define pp pair<int, char> 
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        priority_queue<pp> pq;
        string ans;
        
        for(int i=0; i<s.length(); i++) freq[s[i]]++;
        
        for(auto i: freq) pq.push({i.second, i.first});
        while(pq.size()>1){
            pair<int, char> t1= pq.top();
            pq.pop();
            pair<int, char> t2= pq.top();
            pq.pop();
            ans.push_back(t1.second);
            ans.push_back(t2.second);
            t1.first--;
            t2.first--;
            if(t1.first!=0)
            pq.push(t1);
            if(t2.first!=0)
            pq.push(t2);
                
        }
        if(pq.size()==1 && pq.top().first==1){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return (pq.size()==0)? ans: "";
    }
};