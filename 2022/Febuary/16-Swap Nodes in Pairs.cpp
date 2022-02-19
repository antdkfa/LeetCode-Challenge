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
    
    void goSwap(ListNode* front, ListNode* back) {
        front->next->next = front;
        if(back->next) {
            front->next = back->next;
            if(back->next->next) goSwap(back, back->next->next);
            else back->next->next = back, back->next = nullptr;
        }
        else front->next = back;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newHead = head->next;
        if(!head->next->next) {
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }
        
        goSwap(head, head->next->next);
        return newHead;
    }
};
