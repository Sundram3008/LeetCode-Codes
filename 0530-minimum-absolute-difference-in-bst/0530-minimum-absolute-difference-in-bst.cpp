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
    void helper(TreeNode* root, int &parentVal, int &ans){
        if(root==NULL) return;
        helper(root->left, parentVal, ans);
        if(parentVal>=0) ans= min(ans, abs(root->val-parentVal));
        parentVal=root->val;
        helper(root->right, parentVal, ans);
        
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX, x=-1;
        helper(root, x, ans);
        // int ans= vals[1]-vals[0];
        // for(int i=2; i<vals.size(); i++){
        //     ans= min(ans, vals[i]-vals[i-1]);
        // }
        return ans;
        
    }
};