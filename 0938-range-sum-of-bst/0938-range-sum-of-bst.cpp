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
    void helper(TreeNode* root, int l,int h, int &ans){
        if(root){
            helper(root->left,l,h,ans);
            if(root->val>=l && root->val<=h) ans+= root->val;
            helper(root->right,l,h,ans);
        }
        return;
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        int ans=0;
        helper(root,l,h,ans);
        return ans;
    }
};