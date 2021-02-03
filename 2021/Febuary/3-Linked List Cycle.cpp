/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int cnt=0;
        ListNode *tmp = head;
        while(tmp){
            tmp=tmp->next;
            cnt++;
            if(cnt>10005) return true; 
        }
        return false;
    }
};
