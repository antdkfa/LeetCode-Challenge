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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = head;
        ListNode* before = nullptr;
        
        while(head != nullptr) {
            if(head->val == val) {
                if(head == newHead) {
                    newHead = head->next;
                } else if(head->next == nullptr) {
                    before->next = nullptr;
                    break;
                } else {
                    before->next = head->next;
                }
            } else before = head;
            head = head->next;
        }
        
        return newHead;
    }
};
