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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        int arr[305] = {0, }, idx=0;
        ListNode* ans = new ListNode(-1);
        ListNode* tmp = ans;
        while(head) arr[(head->val)+100]++, head=head->next;
        for(int i = 0;i<=200;i++){
            if(arr[i] == 1) {
                ListNode* insert = new ListNode(i-100);
                tmp->next = insert;
                tmp = insert;
            }
        }
        return ans->next ? ans->next : nullptr;
    }
};
