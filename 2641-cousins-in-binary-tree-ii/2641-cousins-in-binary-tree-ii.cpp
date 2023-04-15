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
#define pp pair<TreeNode*,int>
class Solution {
public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         queue<pp> q;
//         q.push({root, -1});
        
//         unordered_map<int, unordered_map<int,int>> mp;
        
//         int l=0, no=-1;
        
//         vector<int> lvls;
        
//         while(!q.empty()){
            
//             int n= q.size(), sum=0;
            
//             for(int i=0; i<n; i++){
//                 TreeNode* a= q.front().first;
//                 int b= q.front().second;
               
//                 mp[l][b]+= a->val;
                
//                 sum+= a->val;
//                 no++;
//                 if(a->left!=NULL) q.push({a->left, no});
//                 if(a->right!=NULL) q.push({a->right, no});
//                 q.pop();
                
//             }
//             lvls.push_back(sum);
//             l++;
//         }
        
//         q.push({root, -1});
//         l=0, no=-1;
//         while(!q.empty()){
//             int n= q.size(), sum=0;
            
//             for(int i=0; i<n; i++){
//                 TreeNode* a= q.front().first;
//                 int b= q.front().second;
               
//                 a->val= lvls[l]- mp[l][b];
//                 no++;
//                 if(a->left!=NULL) q.push({a->left, no});
//                 if(a->right!=NULL) q.push({a->right, no});
//                 q.pop();
//             }
//             l++;
//         }
        
//         return root;
//     }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int x=0;
        while(!q.empty()){
            int total=0, n= q.size();
            vector<pair<TreeNode*, int>> temp;
            unordered_map<int,int> mp;
            for(int i=0; i<n; i++){
                TreeNode* node= q.front().first;
                int parent= q.front().second;
                q.pop();
                x++;
                total+= node->val;
                mp[parent]+= node->val;
                temp.push_back({node,parent});
                if(node->left) q.push({node->left,x});
                if(node->right) q.push({node->right, x});
            }
            
            for(auto &i: temp){
                TreeNode * node= i.first;
                int parent= i.second;
                int newVal= total- mp[parent];
                node->val= newVal;
            }
        }
        return root;
    }
};