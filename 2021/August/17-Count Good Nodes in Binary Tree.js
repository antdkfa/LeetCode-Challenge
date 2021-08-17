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
var goodNodes = function(root) {
    var ans = 0;
    var nowMax = -1e9;
    
    if(root) dfs(root);
    
    function dfs(now) {
        if(now.val >= nowMax) {
            nowMax = now.val;
            ans++;
        }
        var tmpMax = nowMax;
        
        if(now.left) {
            dfs(now.left);
        }
        
        nowMax = tmpMax;
        
        if(now.right) {
            dfs(now.right);    
        }   
    }
    
    return ans;
};
