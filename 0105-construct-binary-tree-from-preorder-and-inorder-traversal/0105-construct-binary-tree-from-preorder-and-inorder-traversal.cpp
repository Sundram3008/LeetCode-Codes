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
    TreeNode* make(vector<int> &pre, int inStart, int inEnd, int &idx, unordered_map<int,int> &inMap){
        if(inStart> inEnd) return NULL;
        int newInIdx = inMap[pre[idx]];
        TreeNode* root= new TreeNode(pre[idx]);
        idx++;
        root->left= make(pre, inStart, newInIdx-1, idx, inMap);
        root->right= make(pre, newInIdx+1, inEnd, idx, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int idx=0;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]]=i;
        return make(preorder, 0, inorder.size()-1, idx, inMap);
    }
};