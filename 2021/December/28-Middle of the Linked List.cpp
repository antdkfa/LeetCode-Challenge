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
    ListNode* middleNode(ListNode* head) {
        ListNode * getSize = head;
        int size = 0;
        
        while(getSize){
            getSize=getSize->next;
            size++;
        }
        
        ListNode* ans = head;
        for(int i=0;i<size/2;i++) {
            ans = ans->next;
        }
        
        return ans;
    }
};
