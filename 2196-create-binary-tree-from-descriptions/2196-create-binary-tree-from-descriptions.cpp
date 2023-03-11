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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int,bool> isChild;
        for(auto i: desc){
            
            if(nodes.find(i[1])==nodes.end()) nodes[i[1]] = new TreeNode(i[1]);
            if(nodes.find(i[0])==nodes.end()) nodes[i[0]] = new TreeNode(i[0]);
            
            TreeNode* temp;
            temp= nodes[i[1]];
            
            if(i[2]) nodes[i[0]]->left=temp;
            else nodes[i[0]]->right= temp;
            
            isChild[i[1]]=true;
        }
        for(auto i: desc){
            if(isChild.find(i[0])==isChild.end()) return nodes[i[0]];
        }
        return NULL;
    }
};