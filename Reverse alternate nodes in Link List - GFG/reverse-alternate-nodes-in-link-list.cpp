//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd->next==NULL) return;
        Node* h1= odd, *x=h1, *b;
        Node* h2= odd->next, *y=h2;
        int n=0;
        for(Node* temp= odd->next->next; temp!=NULL; temp= temp->next){
            if(n%2==0){
                h1->next= temp;
                h1=h1->next;
            }else{
                h2->next= temp;
                h2= h2->next;
            }
            n++;
        }
        h2->next=NULL;
        //for(Node *temp= y; temp!=NULL; temp= temp->next) cout<<temp->data<<" ";
        Node* prev=NULL, *curr= y, *nexti;
        while(curr!=NULL){
            nexti= curr->next;
            curr->next= prev;
            prev=curr;
            curr= nexti;
        }
        
        h1->next=prev;
        odd= x;
        return ;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends