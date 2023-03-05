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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp= q.front();
                q.pop();
                sum+= temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(pq.size()==k){
                if(pq.top()< sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }else{
                pq.push(sum);
            }
        }
        return pq.size()==k ? pq.top() :-1;
    }
};