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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> m;
        ListNode* tmpB = headB;
        while(tmpB){
            m[tmpB]=1;
            tmpB=tmpB->next;
        }
        ListNode* tmpA = headA;
        while(tmpA){
            if(m[tmpA]) return tmpA;
            tmpA=tmpA->next;
        }
        return nullptr;
    }
};
