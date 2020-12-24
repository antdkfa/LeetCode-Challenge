/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* change(ListNode *a, ListNode *b){
        a->next=b->next;
        b->next = a;
        return b;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        head = change(head,head->next);
        ListNode* now = head;
        if(head->next->next) now=head->next;
        else return now;
        while(1){
            if(now->next && now->next->next){
                now->next = change(now->next, now->next->next);
                now=now->next->next;
            }
            else break;
        }
        return head;
    }
};
