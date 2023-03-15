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
    bool isCompleteTree(TreeNode* root) {
        bool isNull=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp= q.front();
                q.pop();
                
                if(temp->left!=NULL && isNull) return false;
                
                if(temp->left!=NULL) q.push(temp->left);
                else isNull=true;
                
                if(temp->right!= NULL && isNull) return false;
                
                if(temp->right!=NULL) q.push(temp->right);
                else isNull=true;
            }
        }
        return true;
    }
};