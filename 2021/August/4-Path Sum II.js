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
 * @param {number} targetSum
 * @return {number[][]}
 */


var pathSum = function(root, targetSum) {
    var ans = [], arrNow = [], sum = 0;

    function go(now, targetSum) {
        if(!now) return ans;
        sum += now.val;
        arrNow.push(now.val);
        if(!now.left && !now.right) {
            var tmp = JSON.parse(JSON.stringify(arrNow));
            if(targetSum === sum) ans.push(tmp);
        } 
        if(now.left) {
            go(now.left, targetSum);
        }
        if(now.right) {
            go(now.right, targetSum);
        }
        sum -= now.val;
        arrNow.pop();
    }
    go(root, targetSum);
    return ans;
};
