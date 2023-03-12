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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: lists){
            while(i){
                pq.push(i->val);
                i=i->next;
            }
        }
        ListNode* ans= new ListNode(-1), *temp= ans;
        while(!pq.empty()){
            temp->next= new ListNode(pq.top());
            pq.pop();
            temp= temp->next;
        }
        return ans->next;
    }
};