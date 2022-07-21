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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int arr[505] = {0, }, idx = 1;
        while(head) {
            arr[idx++] = head->val;
            head = head->next;
        }
        while(left < right) {
            swap(arr[left++],arr[right--]);
        }
        ListNode* newHead = new ListNode(arr[1]);
        ListNode* tail = newHead;
        for(int i=2;i<idx;i++) {
            ListNode* newNode = new ListNode(arr[i]);
            tail->next = newNode;
            tail = tail->next;
        }
        return newHead;
    }
};
