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
var sumOfLeftLeaves = function(root) {
    let ans=0;
    
    const go =(now,isLeft)=>{
        if(!now.left && !now.right) {
            if(isLeft) ans+= now.val;
        }
        if(now.left) go(now.left, 1);
        if(now.right) go(now.right, 0);
    }
    
    go(root,0);
    return ans;
};
