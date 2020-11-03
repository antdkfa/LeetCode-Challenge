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
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *head1 = head, *head2 = head->next;
        while(head2){
            ListNode * a = head1;
            while(a){
                if(a->next == head2) {
                    a->next = NULL;
                    break;
                }
                a = a->next;
            }
            ListNode *insert = head1;
            if(head2->val <= insert-> val) {
                ListNode * tmp = head2;
                head2 = head2->next;
                tmp->next = insert;   
                head1 = tmp;
            }
            else {
                int flag = 0;
                while(insert->next){
                    if(insert->val <= head2->val && head2->val <= insert->next->val){
                        // 중간에 삽입  
                        ListNode *tmp = head2;
                        head2 = head2->next;
                        tmp->next = insert->next;
                        insert->next = tmp;
                        flag = 1;
                        break;
                    }
                    insert = insert->next;    
                }
                if(!flag){
                    // 삽입 안됐으면 맨 끝에 삽입
                    insert->next = head2;
                    head2 = head2->next;
                }
            }    
        }
        return head1;
    }
};
