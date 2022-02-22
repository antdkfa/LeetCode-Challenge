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
    int ans = 0;
    
    int convertToDecimal(String s) {
        int sum = 0;
        for(int i=s.length()-1,j=1;i>=0;i--,j*=2) {
            sum += (s.charAt(i) - '0') * j;
        }
        return sum;
    }
    
    void dfs(TreeNode now, String s) {
        String newS = s + now.val;
        if(now.left == null && now.right == null) {
            ans += convertToDecimal(newS);
            return;
        }
        if(now.left != null) dfs(now.left, newS);
        if(now.right != null) dfs(now.right, newS);
    }
    
    public int sumRootToLeaf(TreeNode root) {
        dfs(root, "");
        return ans;
    }
}
