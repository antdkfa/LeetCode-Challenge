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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> s1,s2;
        string now = "";
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int o = 0;
        while(!s1.empty() && !s2.empty()){
            int next = s1.top() + s2.top() + o;
            now+=to_string(next%10);
            if(next >= 10) o = 1; 
            else o = 0;
            s1.pop(), s2.pop();
        }
        while(!s1.empty()){
            int next = s1.top() + o;
            now+=to_string(next%10);
            if(next >= 10) o = 1;
            else o = 0;
            s1.pop();
        }
        while(!s2.empty()){
            int next = s2.top() + o;
            now+=to_string(next%10);
            if(next >= 10) o = 1;
            else o = 0;
            s2.pop();
        }
        if(o) now += "1";
        reverse(now.begin(), now.end());
        ListNode *head = new ListNode(now[0] - '0');
        ListNode *before = head;
        for(int i = 1;i<now.length();i++){
            ListNode *tmp = new ListNode(now[i] - '0');
            before-> next = tmp;
            before = before->next;
        }
        return head;
    }
};
