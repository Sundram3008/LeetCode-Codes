//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
#define ll long long
#define all(x) x.begin(), x.end()
    long long solve(int n, vector<int> &a, vector<int> &b) {
        // code here
        vector<ll> ea, eb, oa, ob;
        ll sum=0;
        for(int i=0; i<n; i++){
            if(a[i]%2){
                oa.push_back(a[i]);
            }else{
                ea.push_back(a[i]);
            }
            sum+= a[i]-b[i];
            if(b[i]%2){
                ob.push_back(b[i]);
            }else{
                eb.push_back(b[i]);
            }
        }
        if(sum!=0 || oa.size()!= ob.size()) return -1;
        sort(all(ea));
        sort(all(eb));
        sort(all(oa));
        sort(all(ob));
        ll total=0;
        for(int i=0; i<ea.size(); i++)
            total+= abs(ea[i]-eb[i]);
        
        for(int i=0; i<oa.size(); i++)
            total+= abs(oa[i]-ob[i]);
            
        return total/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends