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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;
        
        while(1) {
            ListNode* oddNow = odd;
            ListNode* evenNow = even;
            if(odd->next && odd->next->next) {
                odd = odd->next->next;
            } 
            if(even->next && even->next->next) {
                even = even->next->next;
            }
            
            if(odd == oddNow) break;
            oddNow->next = odd;
            if(even == evenNow) {
                even->next = nullptr;
                break;
            }
            evenNow->next = even;
        }
        
        odd->next = evenHead;
        
        return head;
    }
};
