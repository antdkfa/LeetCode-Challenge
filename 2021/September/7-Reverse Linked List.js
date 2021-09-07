/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(!head) return head;
    
    let ans;
    const dfs = (now) => {
        if(now.next !== null) {
            dfs(now.next);
            now.next.next = now;
        } else {
            ans = now;
        }
    }
    dfs(head);
    head.next = null;
    return ans;
};
