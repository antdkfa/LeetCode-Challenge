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
    int ret = 0;
    private void search(TreeNode now) {
        if(now.right != null) search(now.right);
        ret += now.val;
        now.val = ret;
        if(now.left != null) search(now.left);
    } 
    public TreeNode convertBST(TreeNode root) {
        if(root == null) return root;
        search(root);
        return root;
    }
}
