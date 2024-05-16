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
    public boolean evaluateTree(TreeNode root) {
        if(root==null) return true;
        int x= root.val;
        boolean opl= evaluateTree(root.left);
        boolean opr= evaluateTree(root.right);
        if(x==0) return false;
        else if(x==1) return true;
        else if(x==2) return opl| opr;
        else return opl&opr;
    }
}