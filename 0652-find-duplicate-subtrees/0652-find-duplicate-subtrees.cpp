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
    /*map<vector<int>, TreeNode*> mp;
    set<vector<int>> st;
    vector<int> dfs(TreeNode* root){
        if(root==NULL) return {-201};
        vector<int> left= dfs(root->left);
        vector<int> right= dfs(root->right);
        vector<int> total;
        for(auto i: left){
            total.push_back(i);
        }
        for(auto i: right){
            total.push_back(i);
        }
        total.push_back(root->val);
        if(mp.find(total)!=mp.end()){ 
            mp[total]=root;
            st.insert(total);
        }
        else mp[total]=root;
        return total;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> ans;
        for(auto i: st){
            ans.push_back(mp[i]);
        }
        return ans;
    }*/
    // Little Optimised//
    unordered_map<string, vector<TreeNode*>> mp;
    string dfs(TreeNode* root){
        if(!root) return "";
        string temp= "(" + dfs(root->left) + to_string(root->val) + dfs(root->right) + ")";
        mp[temp].push_back(root);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        dfs(root);
        for(auto i: mp){
            if(i.second.size()>1) ans.push_back((i.second)[0]);
        }
        return ans;
    }
};