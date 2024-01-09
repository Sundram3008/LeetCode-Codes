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
    void inorder(TreeNode* root, vector<int> &v){
        if(root && root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        if(root){
            inorder(root->left, v);
            inorder(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        inorder(root1, r1);
        inorder(root2, r2);
        return (r1==r2);
    }
};