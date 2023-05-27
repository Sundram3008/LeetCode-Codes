//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    
    Node* reverse(Node* curr){
        Node* nextNode, *prev=NULL;
        while(curr!=NULL){
            nextNode= curr->next;
            curr->next= prev;
            prev=  curr;
            curr= nextNode;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        if(head->next==NULL) return head;
        int cnt=0;
        for(Node* i=head; i!=NULL; i=i->next) cnt++;
        Node* revList=reverse(head);
        cnt= (cnt+1)/2;
        Node* temp=revList, *prev=temp, *t2=revList;
        for(int i=1; i<=cnt; i++){
            prev= temp;
            temp= temp->next;
        }
        prev->next=reverse(temp);
        int j=0;
        temp= revList;
        for(Node* i=revList; i!=NULL; i=i->next){
            ++j;
            if(j>cnt){
                temp->data= temp->data - i->data;
                temp= temp->next;
            }else{
                prev=i;
                t2= t2->next;
            }
            
        }
        prev->next= reverse(t2);
        return revList;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends