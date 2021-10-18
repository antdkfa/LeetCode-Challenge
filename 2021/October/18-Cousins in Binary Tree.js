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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    const arr = Array.from({length: 105}, () => 0);
    
    const go = (root, parent, depth) => {
        arr[root.val] = {parent: parent, depth: depth};
        if(root.left) go(root.left, root.val, depth + 1);
        if(root.right) go(root.right, root.val, depth + 1);
    }
    
    go(root,-1,0);
    return (arr[x].parent != arr[y].parent && arr[x].depth == arr[y].depth);
};
