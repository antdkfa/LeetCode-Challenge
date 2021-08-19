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
var maxProduct = function(root) {
    let sum = 0;
    let ans = -1;
    const MOD = 1e9+7;
    
    const getAns = now => {
        let tmp = now.val;
        if(now.left || now.right) {
            tmp = now.val;
            if(now.left) {
                tmp += getAns(now.left);
            }
            if(now.right) {
                tmp += getAns(now.right);
            }
        }
        ans = Math.max(ans, (sum - tmp) * tmp);
        return tmp;
    };
    
    const getTotalSum = now => {
        sum += now.val;
        if(now.left) getTotalSum(now.left);
        if(now.right) getTotalSum(now.right);
    }
    
    getTotalSum(root);
    getAns(root);
    ans %= MOD;
    return ans; 
    
    
};
