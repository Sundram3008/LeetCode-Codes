//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int v){
        if(v<=1) return false;
        for(int i=2; i<= sqrt(v); i++){
            if(v%i==0) return false;
        }
        return true;
    }
    Node *primeList(Node *head){
        for(Node *temp= head; temp!=NULL; temp= temp->next){
            int m= temp->val-1, n= temp->val+1;
            if(!isPrime(temp->val)){
                while(true){
                    if(isPrime(m)){
                        temp->val= m;
                        break;
                    }
                    if(isPrime(n)){
                        temp->val= n;
                        break;
                    }
                    m--;
                    n++;
                }
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends