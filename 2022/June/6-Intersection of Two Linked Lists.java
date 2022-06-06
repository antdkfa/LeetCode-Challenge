/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Map<ListNode,Integer> m = new HashMap<>();
        while(headA != null) {
            m.put(headA, 1);
            headA = headA.next;
        }
        
        while(headB != null) {
            if(m.containsKey(headB)) return headB;
            headB = headB.next;
        }
        return null;
    }
}
