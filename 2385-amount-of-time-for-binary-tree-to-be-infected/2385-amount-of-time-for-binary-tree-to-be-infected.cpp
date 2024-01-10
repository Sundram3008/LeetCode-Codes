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
    
    void helper(TreeNode* root, int parent, unordered_map<int , vector<int>> &mp){
        if(root== NULL) return;
        if(parent!= -1){
            mp[root->val].push_back(parent);
            mp[parent].push_back(root->val);
        }
        helper(root->left, root->val, mp);
        helper(root->right, root->val, mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;
        helper(root, -1, mp);
        
        queue<int> q;
        unordered_set<int> visited;
        int res=0;
        
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int n= q.size();
            for(int i=1; i<=n; i++){
                int val= q.front();
                q.pop();
                
                for(int j: mp[val]){
                    if(visited.find(j)==visited.end()){
                        q.push(j);
                        visited.insert(j);
                    }
                }
            }
            res++;
        }
        return res-1;
    }
};