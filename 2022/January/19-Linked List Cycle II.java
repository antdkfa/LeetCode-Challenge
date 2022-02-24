/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    HashMap<ListNode, Integer> map = new HashMap<>();
    ListNode ans;
    void dfs(ListNode now) {
        if(now == null) return;
        if(map.containsKey(now)) {
            ans = now;
        } else {
            map.put(now,1);
            dfs(now.next);
        }
    }
    
    public ListNode detectCycle(ListNode head) {
        dfs(head);
        return ans;
    }
}
