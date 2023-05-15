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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        for(ListNode *temp= head; temp!=NULL; temp=temp->next){
            n++;
        }
        int cnt=1, c=0, cnt1=0;
        ListNode* x=head, *y=head;
        for(ListNode *temp= head; temp!=NULL; temp= temp->next){
            if(cnt==k) x=temp;
            if(cnt1==n-k) y=temp;
            cnt++;
            cnt1++;
        }
        c=x->val;
        x->val = y->val;
        y->val=c;
        return head;
    }
};