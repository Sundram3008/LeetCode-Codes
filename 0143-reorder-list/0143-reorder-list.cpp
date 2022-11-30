/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next==NULL) return ;
        ListNode *prev = NULL, *nxt, *slow= head, *fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* curr = slow->next;
        while(curr!=NULL){
            nxt= curr->next;
            curr->next=prev;
            prev= curr;
            curr= nxt;
        }
        slow->next=NULL;
        ListNode* temp=head;
        while(prev!=NULL){
            ListNode* c= temp->next, *x=prev->next;
            temp->next= prev;
            temp->next->next= c;
            prev= x;
            temp=c;
        }
        return ;
    }
};