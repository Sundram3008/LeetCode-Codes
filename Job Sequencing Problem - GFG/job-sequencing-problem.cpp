//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
#define pp pair<int,int>
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool mycomp(Job a, Job b){
        if(a.dead!= b.dead) return a.dead< b.dead;
        else return a.profit> b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int cnt=0, sum=0, prev=0;
        sort(arr, arr+n, mycomp);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i=0; i<n; i++){
            if(cnt>=arr[i].dead){
                if(!pq.empty() && pq.top().first< arr[i].profit){
                    sum-= pq.top().first;
                    sum+= arr[i].profit;
                    pq.push({arr[i].profit, pq.top().second});
                    pq.pop();
                }
            }else{
                cnt++;
                sum+= arr[i].profit;
                pq.push({arr[i].profit, cnt});
            }
            //cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<endl;
        }
        return {cnt, sum};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends