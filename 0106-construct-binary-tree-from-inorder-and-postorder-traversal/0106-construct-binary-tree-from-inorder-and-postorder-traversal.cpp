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
//   TC - O(N^2), SC - O(N)
//     TreeNode* make(unordered_map<int,int> &mp, vector<int> &in, vector<int> &post){
//         if(mp.size()==0) return NULL;
//         int idx=-1;
//         for(int i=post.size()-1; i>=0; i--){
//             if(mp.find(post[i])!=mp.end()){
//                 idx=mp[post[i]];
//                 break;
//             }
//         }
        
//         if(idx==-1) return NULL;
//         TreeNode* root= new TreeNode(in[idx]);
        
//         unordered_map<int,int> lefts, rights;
//         for(auto i: mp){
//             if(i.second<idx) lefts[i.first]=i.second;
//             if(i.second>idx) rights[i.first]=i.second;
//         }
        
//         root->left= make(lefts, in, post);
//         root->right= make(rights, in, post);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         // requirements will need two unordered map to have left and right elements they will be present with their respective indices 
//         // iterate from right to left in postorder again and again to find the root node and find that node in inorder the index at which it will be present from that the left elements will be forming left subtree and right elements will form right subtree
//         // repeat the process recursively till all left and right elements are consumed
        
//         unordered_map<int,int> mp;
//         for(int i=0; i<inorder.size(); i++){
//             mp[inorder[i]]=i;
//         }
//         return make(mp, inorder, postorder);
        
//     }
    
    // Optimised - TC- O(N) and SC- O(N)
    
    TreeNode* make(vector<int> &post, int inStart, int inEnd, int &postIdx, unordered_map<int,int> &inMap){
        if(inStart> inEnd) return NULL;
        int newInIdx= inMap[post[postIdx]];
        TreeNode *root= new TreeNode(post[postIdx]);
        postIdx--;
        root->right= make(post, newInIdx+1, inEnd, postIdx, inMap);
        root->left= make(post, inStart, newInIdx-1, postIdx, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        int n= inorder.size()-1;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]]=i;
        return make(postorder, 0, n, n, inMap);
    }
    
};