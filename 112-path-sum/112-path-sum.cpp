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
    bool flag;
    void helper(TreeNode* root, int tSum, int currSum){
        if(root==NULL) return ;
        currSum+= root->val;
        helper(root->left, tSum, currSum);
        helper(root->right,tSum, currSum);
        if(root->left==NULL && root->right==NULL){
            if(tSum==currSum) {
                flag=true;
                return;
            }
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        flag=false;
        helper(root,targetSum,0);
        return flag;
    }
};