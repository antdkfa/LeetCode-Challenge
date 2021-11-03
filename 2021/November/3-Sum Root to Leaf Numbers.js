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
var sumNumbers = function(root) {
    let ans = 0;
    
    let go=(now, sum)=>{
        if(!now) return
        sum*=10;
        sum+=now.val;
        if(!now.left && !now.right) {
            ans += sum;
            return;
        }
        go(now.left, sum);
        go(now.right, sum);
    }
    
    go(root, 0);
    
    return ans;
};
