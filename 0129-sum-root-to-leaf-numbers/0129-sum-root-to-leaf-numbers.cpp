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
    int sum=0;
    void helper(TreeNode* root, int &prev){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            prev= (prev*10)+root->val;
            sum+= prev;
            prev/=10;
            return;
        }
        prev= (prev*10)+root->val;
        helper(root->left, prev);
        helper(root->right, prev);
        prev/=10;
    }
    int sumNumbers(TreeNode* root) {
        int prev=0;
        helper(root, prev);
        return sum;
    }
};