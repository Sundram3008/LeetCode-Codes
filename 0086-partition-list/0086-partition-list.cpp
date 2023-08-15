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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s= new ListNode(-1), *st= s, *h= new ListNode(-1), *ht=h;
        while(head!=NULL){
            if(head->val<x){
                st->next= new ListNode(head->val);
                st= st->next;
            }else{
                ht->next= new ListNode(head->val);
                ht= ht->next;
            }
            head=head->next;
        }
        if(s->next==NULL) return h->next;
        else{
            st->next=h->next;
            return s->next;
        }
    }
};