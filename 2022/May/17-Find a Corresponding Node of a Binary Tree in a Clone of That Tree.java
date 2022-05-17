/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    private class Pair {
        TreeNode a;
        TreeNode b;
        Pair(TreeNode a, TreeNode b) {
            this.a = a;
            this.b = b;
        }
    }
    
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(original, cloned));
        while(!q.isEmpty()) {
            Pair now = q.poll();
            if(now.a == target) {
                return now.b;
            }
            if(now.a.left != null) q.add(new Pair(now.a.left, now.b.left));
            if(now.a.right != null) q.add(new Pair(now.a.right, now.b.right));
        }
        return null;
    }
}
