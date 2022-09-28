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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            sz++;
        }
        if(n==sz) return head->next;
        sz= sz-n;
        temp=head;
        while(temp && --sz){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete(del);
        return head;
    }
};