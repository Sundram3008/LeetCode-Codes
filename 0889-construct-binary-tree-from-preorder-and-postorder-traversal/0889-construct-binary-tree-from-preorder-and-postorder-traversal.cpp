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
//     TC- O(n^2), SC- O(n)
//     TreeNode* make(vector<int> &pre, int &idx, unordered_map<int,int> postMap){
//         if( idx>= pre.size() || postMap.size()==0) return NULL;
//         if(postMap.find(pre[idx])==postMap.end()) return NULL;
//         int newIdx= postMap[pre[idx]];
//         TreeNode * root= new TreeNode(pre[idx]);
//         idx++;
//         unordered_map<int,int> newMap;
//         for(auto i: postMap){
//             if(i.second<newIdx){
//                 newMap[i.first]=i.second;
//             }
//         }
//         root->left= make(pre, idx, newMap);
//         root->right= make(pre, idx, newMap);
//         return root;
        
//     }
//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         unordered_map<int, int> mp;
//         int idx=0;
//         for(int i=0; i<postorder.size(); i++) mp[postorder[i]]=i;
//         return make(preorder, idx, mp);
//     }
    
    int pre=0, post=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root= new TreeNode(preorder[pre++]);
        if(root->val!=postorder[post]) root->left= constructFromPrePost(preorder, postorder);
        if(root->val!=postorder[post]) root->right= constructFromPrePost(preorder, postorder);
        post++;
        return root;
    }
    
};