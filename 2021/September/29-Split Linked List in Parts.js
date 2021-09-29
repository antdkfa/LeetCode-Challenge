/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode[]}
 */
var splitListToParts = function(head, k) {
    const arr = [];
    while(head) {
        arr.push(head.val);
        head = head.next;
    }
    
    const size = Math.floor(arr.length / k);
    const remainder = arr.length % k;
    
    let ans = [];
    for(let i=0;i<k;i++) {
        let nhead = new ListNode(null);
        let ntail;
        let p = i < remainder ? 1 : 0;
        for(let j=0;j<size + p;j++) {
            let now = new ListNode(arr.shift());
            if(!j) {
                nhead = now;
                ntail = nhead;
            } else {
                ntail.next = now;
                ntail = ntail.next;
            }
        }
        
        if(nhead.val === null) ans.push(null);
        else ans.push(nhead);
   }
    return ans;
};
