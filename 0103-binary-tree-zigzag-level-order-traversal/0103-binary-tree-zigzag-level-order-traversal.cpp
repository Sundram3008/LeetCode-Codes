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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int cnt=0;
        while(!q.empty()){
            int n= q.size();
            vector<int> v(n,0);
            for(int i=0; i<n; i++){
                TreeNode* temp= q.front();
                q.pop();
                if(cnt%2==0){
                    v[i]=temp->val;
                }else {
                    v[n-i-1]=temp->val;
                }
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            ans.push_back(v);
            cnt++;
        }
        return ans;
    }
};