class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        deque<int> dq(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        while(dq.front()!= maxi){
            int f= dq.front();
            dq.pop_front();
            int s= dq.front();
            dq.pop_front();
            int x= max(s,f);
            mp[x]++;
            if(mp[x]==k) return x;
            if(s<f){
                dq.push_back(s);
                dq.push_front(f);
            }else{
                dq.push_back(f);
                dq.push_front(s);
            }
        }
        return dq.front();
    }
};