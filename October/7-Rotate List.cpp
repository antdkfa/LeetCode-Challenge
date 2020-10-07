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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp = head;
        if(head == NULL || head->next ==NULL) return head;
        int listsize = 1;
        ListNode *tail = head;
        ListNode *newhead = head;
        ListNode *newtail = head;
        while(tail->next != NULL) tail = tail->next, listsize++;
        k%=listsize;
        if(!k) return newhead;
        tail->next = head;
        for(int i = 0;i<listsize - k;i++) newhead = newhead->next;
        while(newtail->next != newhead) newtail = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};
