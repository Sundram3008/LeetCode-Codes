/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node* temp=head;
        while(temp){
            mp[temp]= new Node(temp->val);
            temp= temp->next;
        }
        temp=head;
        Node* res= new Node(-1), *ans=res;
        while(temp!=NULL){
            res->next=mp[temp];
            res=res->next;
            res->next= mp[temp->next];
            res->random= mp[temp->random];
            res=res->next;
            temp= temp->next;
        }
        return ans->next;
    }
};