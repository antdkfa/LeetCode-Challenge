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
    private TreeNode search(TreeNode now, int val) {
        if(now == null) return null;
        if(now.val == val) {
            return now;
        }
        if(now.val < val) {
            return search(now.right, val);
        } else return search(now.left, val);
    }
    public TreeNode searchBST(TreeNode root, int val) {
        return search(root, val);
    }
}
