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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        int first,last,ans=0;
        while(!q.empty()){
            int n=q.size();
            int mini= q.front().second;
            for(int i=0; i<n; i++){
                long long curr= q.front().second -mini;
                TreeNode* temp= q.front().first;
                q.pop();
                if(i==0) first= curr;
                if(i==n-1) last= curr;
                if(temp->left) q.push({temp->left, curr*2 +1});
                if(temp->right) q.push({temp->right, curr*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};