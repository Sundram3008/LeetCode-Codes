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
    public int minDepth(TreeNode root) {
        if(root== null) return 0;
        int mini=Integer.MAX_VALUE;
        if(root.left == null && root.right==null) return 1;
        else if(root.left== null && root.right!=null){
            mini= Math.min(minDepth(root.right), mini);
        }else if(root.left!=null && root.right==null){
            mini= Math.min(minDepth(root.left), mini);
        }else{
            mini= Math.min(minDepth(root.left), Math.min(minDepth(root.right), mini));
        }
        return mini+1;
    }
}