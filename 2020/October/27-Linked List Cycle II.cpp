/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode * now = head;
        ListNode * ans = NULL;
        while(now){
            if(now->val > 100000 || now->val < -100000) {
                ans = now;
                break;
            }
            else {
                now->val *= 100001;
                now = now->next;
            }
        }
        now = head;
        while(1){
            if(now->val > 100000 || now->val < -100000) now->val /=100001;
            else break;
        }
        return ans;
    }
};
