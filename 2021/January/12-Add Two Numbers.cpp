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
        string a="",b="",c="";
        int up = 0;
        while(l1) {
            a+=(l1->val) + '0';
            l1=l1->next;
        }
        while(l2){
            b+=(l2->val) + '0';
            l2=l2->next;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = a.length() -1, j=b.length()-1;;i--,j--){
            if(i<0&&j<0) break;
            int x=0,y=0;
            if(i>=0) x=a[i]-'0';
            if(j>=0) y=b[j]-'0';
            int now=x+y+up;
            if(now>=10) up=1,now-=10;
            else up=0;
            c+=now+'0';
        }
        if(up) c+='1';
        ListNode* head=new ListNode(c[0]-'0');
        ListNode* tail = head;
        for(int i=1;i<c.length();i++){
            ListNode* tmp=new ListNode(c[i]-'0');
            tail->next=tmp;
            tail=tail->next;
        }
        return head;
    }
};
