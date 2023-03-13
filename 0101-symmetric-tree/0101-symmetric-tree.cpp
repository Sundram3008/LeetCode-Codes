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
    bool isMirror(TreeNode * lr, TreeNode* rr){
        if(lr==NULL && rr==NULL) return true;
        if(lr==NULL || rr==NULL) return false;
        return (lr->val==rr->val) && isMirror(lr->left, rr->right) && isMirror(lr->right, rr->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
        
    }
};