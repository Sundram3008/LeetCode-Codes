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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode *tail = NULL) {
        if(head==tail) return NULL;
        if(head->next== tail) return new TreeNode(head->val);
        ListNode* mid= head, *end=head;
        while(end != tail && end->next!=tail){
            mid= mid->next;
            end= end->next->next;
        }
        TreeNode * root= new TreeNode(mid->val);
        root->left= sortedListToBST(head, mid);
        root->right= sortedListToBST(mid->next, tail);
        return root;
    }
};