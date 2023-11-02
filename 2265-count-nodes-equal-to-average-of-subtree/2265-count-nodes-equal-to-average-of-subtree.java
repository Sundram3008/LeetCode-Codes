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
    pair<int, int> helper(TreeNode* root, int &ans){
        if(root==NULL) return {0,0};
        if(root->left==NULL && root->right==NULL){
            ans+=1;
            return {root->val, 1};
        }
        //if(ans>=1) cout<< root->val<<endl;
        pair<int, int> x= helper(root->left, ans);
        pair<int, int> y= helper(root->right, ans);
        int val = x.first+ y.first+ root->val;
        int n= x.second+ y.second+ 1;
        if(val/n == root->val) ans++;
        return {val, n};
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        helper(root, res);
        return res;
    }
};