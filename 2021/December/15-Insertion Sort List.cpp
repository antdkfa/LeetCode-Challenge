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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        sort(v.begin(),v.end());
        ListNode* newHead = new ListNode(v[0]);
        ListNode* tail = newHead;
        for(int i=1;i<v.size();i++) {
            ListNode* newNode = new ListNode(v[i]);
            tail->next = newNode;
            tail = tail->next;
        }
        return newHead;
    }
};
