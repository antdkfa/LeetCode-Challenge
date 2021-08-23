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
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function(root, k) {
    let ans = false;
    const visited = [];
    
    const go = (now) => {
        if(visited[JSON.stringify(k - now.val)]) ans = true;
        visited[JSON.stringify(now.val)] = 1;
        if(now.left) {
            go(now.left);
        }
        if(now.right) {
            go(now.right);
        }
    }
    
    go(root);
    return ans;
};
