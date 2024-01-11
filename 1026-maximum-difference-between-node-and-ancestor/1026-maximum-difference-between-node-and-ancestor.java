/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    public void helper(TreeNode root, int mini, int maxi){
        if(root==null) return ;
        if(mini != Integer.MAX_VALUE && maxi!= -1)
        ans= Math.max(ans, Math.max(Math.abs(root.val- mini), Math.abs(root.val-maxi)));
        mini = Math.min(mini, root.val);
        maxi = Math.max(maxi, root.val);
        helper(root.left, mini, maxi);
        helper(root.right, mini, maxi);
    }
    public int maxAncestorDiff(TreeNode root) {
        helper(root, Integer.MAX_VALUE, -1);
        return ans;
    }
}