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
    int sumNumbers(TreeNode* root, int prev=0) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            prev= (prev*10)+root->val;
            return prev;
        }
        prev= (prev*10)+root->val;
        return sumNumbers(root->left, prev) + sumNumbers(root->right, prev);
    }
};