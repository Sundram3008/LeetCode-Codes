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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int lvl=0;
        while(q.isEmpty()==false){
            int n= q.size();
            int prev=0;
            if((lvl%2) ==1) prev= 1000001;
            for(int i=1; i<=n; i++){
                TreeNode x= q.peek();
                q.remove();
                if((lvl%2)==0){
                    if(x.val%2 ==0 || prev>= x.val) return false;
                }else{
                    if(x.val%2 ==1 || prev<= x.val) return false;
                }
                prev= x.val;
                if(x.left!=null) q.add(x.left);
                if(x.right!= null) q.add(x.right);
            }
            lvl++;
        }
        return true;
    }
}