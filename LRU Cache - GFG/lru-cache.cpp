//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    unordered_map<int,pair<int,int>> mp;
    deque<pair<int,int>> q;
    int cap=0, t=0;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->cap=cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        t++;
        if(mp.find(key)==mp.end()){
            return -1;
        }else{
            mp[key]={mp[key].first,t};
            q.push_front({key,t});
            while(q.size()>0){
                if(mp[q.back().first].second!= q.back().second){
                    q.pop_back();
                }else{
                    break;
                }
            }
            return mp[key].first;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        t++;
        mp[key]= {value,t};
        q.push_front({key,t});
        while(q.size()>0){
            if(mp[q.back().first].second!= q.back().second){
                q.pop_back();
            }else{
                break;
            }
        }
        if(mp.size()>cap){
            mp.erase(q.back().first);
            q.pop_back();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends