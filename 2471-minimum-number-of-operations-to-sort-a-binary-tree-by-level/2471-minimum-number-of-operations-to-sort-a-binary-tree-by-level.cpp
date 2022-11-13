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
    int helper(vector<int> nums){
        int len = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < len; i++)
            mp[nums[i]] = i;
        sort(nums.begin(), nums.end());
        vector<bool> visited(len,false);
        int ans = 0;
        for(int i = 0; i < len; i++) {
            if(visited[i] || mp[nums[i]] == i)
                continue;
            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycle_size++;
            }
            if(cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            vector<int> v;
            int n= q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp= q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            ans+=helper(v);
        }
        return ans;
    }
};