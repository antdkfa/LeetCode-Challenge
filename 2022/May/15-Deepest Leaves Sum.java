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
    private class Pair {
        TreeNode a;
        int depth;
        Pair(TreeNode a, int depth) {
            this.a = a;
            this.depth = depth;
        }
    }
    public int deepestLeavesSum(TreeNode root) {
        int ans = 0, depth = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()) {
            Pair now = q.poll();
            if(depth == now.depth) ans += now.a.val;
            else {
                depth = now.depth;
                ans = now.a.val;
            }
            if(now.a.left != null) q.add(new Pair(now.a.left, now.depth + 1));
            if(now.a.right != null) q.add(new Pair(now.a.right, now.depth + 1));
        }
        return ans;
    }
}
