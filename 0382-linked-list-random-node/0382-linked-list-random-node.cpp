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
    ListNode* temp;
    Solution(ListNode* head) {
        temp=head;
    }
    
    int getRandom() {
        int ans=0, i=1;
        ListNode* pT= temp;
        while(pT!=NULL){
            if(rand()%i==0) ans= pT->val;
            i++;
            pT= pT->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */