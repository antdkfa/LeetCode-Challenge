/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var countNodes = function(root) {
    if(!root) return 0;
    
    let ans = 0;
    const go = (now) => {
        ans++;
        if(now.left) go(now.left);
        if(now.right) go(now.right);
    }
    
    go(root);
    
    return ans;
};
