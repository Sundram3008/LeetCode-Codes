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
    void helper(TreeNode* root, vector<vector<int>> &ans, vector<int> paths){
        if(root==NULL) {
            return;
        }

        paths.push_back(root->val);
        helper(root->left, ans, paths);
        helper(root->right, ans, paths);
        if(root && root->left==nullptr && root->right==nullptr){
                ans.push_back(paths);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> temp;
        vector<vector<int>> ans;
        vector<int> paths;
        helper(root,temp,paths);
        for(auto i: temp){
            int sum=0;
            for(auto j:i){
                sum+=j;
            }
            if(sum==targetSum){
                ans.push_back(i);
            }
        }
        return ans;
    }
};