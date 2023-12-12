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
    List<Integer> ans = new ArrayList<>();

    void dfs(TreeNode now) {
        if(now == null) {
            return;
        }
        dfs(now.left);
        ans.add(now.val);
        dfs(now.right);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }
}
