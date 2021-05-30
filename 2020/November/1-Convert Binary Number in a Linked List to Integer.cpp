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
    int getDecimalValue(ListNode* head) {
        if(head == NULL) return 0;
        int size = 0, ans = 0, n = 1;
        ListNode * nhead = head;
        while(nhead) nhead = nhead->next,size++;
        n <<= (size-1);
        while(head){
            ans += head->val * n;
            head = head->next;
            n/=2;
        }
        return ans;
    }
};
