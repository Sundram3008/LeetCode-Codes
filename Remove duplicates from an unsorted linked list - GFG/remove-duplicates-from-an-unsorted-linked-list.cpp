//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
      unordered_set<int> st;
    //  Node* temp=head;
    //  while(temp!=NULL){
    //      Node* x=temp;
    //      while(x->next !=NULL && st.find(x->next->data)!=st.end()){
    //         x= x->next;
    //      }
    //      st.insert(temp->data);
    //      temp->next=x;
    //      temp= temp->next;
    //  }
    //  return head;
    
        Node* ans= new Node(-1), *temp=ans;
        while(head!=NULL){
            if(st.find(head->data)==st.end()){
                temp->next= new Node(head->data);
                temp= temp->next;
            }
            st.insert(head->data);
            head= head->next;
        }
        return ans->next;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends