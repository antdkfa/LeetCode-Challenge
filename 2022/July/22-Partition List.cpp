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
        vector<int> less;
        vector<int> greater;
        ListNode* now = head;
        while(now) {
            if(now->val < x) {
                less.push_back(now->val);
            } else {
                greater.push_back(now->val);
            }
            now = now->next;
        }
        
        if(!less.size()) return head;
        
        ListNode* start;
        ListNode* tail;
        for(int i=0;i<less.size();i++) {
            ListNode* newNode = new ListNode(less[i]);
            if(!i) {
                start = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        for(int i=0;i<greater.size();i++) {
            ListNode* newNode = new ListNode(greater[i]);
            tail->next = newNode;
            tail = tail->next;
        }
        return start;
    }
};
