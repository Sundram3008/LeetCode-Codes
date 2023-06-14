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
    vector<int> vals;
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        vals.push_back(root->val);
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        int ans= vals[1]-vals[0];
        for(int i=2; i<vals.size(); i++){
            ans= min(ans, vals[i]-vals[i-1]);
        }
        return ans;
        
    }
};