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
    ListNode* partition(ListNode* head, int x) {
        vector<int> front, back;
        while(head) {
            if(head->val < x) front.push_back(head->val);
            else back.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<back.size();i++) front.push_back(back[i]);
        ListNode *nhead = new ListNode();
        ListNode *ntail = new ListNode();
        nhead = ntail;
        for(int i=0;i<front.size();i++) {
            ListNode *now = new ListNode(front[i]);
            ntail->next = now;
            ntail = ntail->next;
        }
        nhead = nhead->next;
        return nhead;
    }
};
