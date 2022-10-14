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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return nullptr;
        if(head->next->next==NULL){
            head->next= nullptr;
            return head;
        }
        ListNode* fast=head, *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        slow->val=slow->next->val;
        ListNode* temp= slow->next;
        slow->next=slow->next->next;
        delete(temp);
        temp=nullptr;
        return head;
        
    }
};