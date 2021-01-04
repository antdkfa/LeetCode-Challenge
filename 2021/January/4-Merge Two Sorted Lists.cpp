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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return nullptr;
        ListNode* root = new ListNode();
        ListNode* now =root;
        while(l1 && l2) {
            ListNode* tmp;
            if(l1->val < l2->val) {
                tmp = new ListNode(l1->val), l1=l1->next;
            }
            else tmp = new ListNode(l2->val), l2=l2->next;
            now->next=tmp;
            now=now->next;
        }
        while(l1){
            now->next = new ListNode(l1->val);
            now=now->next,l1=l1->next;
        }
        while(l2){
            now->next = new ListNode(l2->val);
            now=now->next, l2=l2->next;
        }
        root=root->next;
        return root;
    }
};
