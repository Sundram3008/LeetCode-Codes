/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans= NULL;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL ) return 0;
        
        int x= (root->val==p->val) + (root->val == q->val);
        x+= dfs(root->left, p, q)+ dfs(root->right, p, q);
        if(x>=2){
            if(ans==NULL) ans= root;
        }
        return x;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool fp=false, fq=false;
        dfs(root, p, q);
        return ans;
    }
};