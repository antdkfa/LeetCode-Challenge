/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    const ans = [];
    if(!root) return ans;
    
    const bfs = () => {
        const q = [];
        q.push([root, 0]);
        while(q.length) {
            let now = q[0][0], depth = q[0][1];
            if(!ans[depth]) ans.push([]);
            ans[depth].push(now.val);
            q.shift();
            now.children.forEach((child) => {
                q.push([child, depth + 1]);
            })
        }
    }
    
    bfs();
    return ans;
};
