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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            ListNode* now=lists[i];
            while(now){
                v.push_back(now->val);
                now=now->next;
            }
        }
        if(!v.size()) return nullptr;
        sort(v.begin(),v.end());
        ListNode* ans = new ListNode(v[0]),*tail = ans;
        for(int i=1;i<v.size();i++){
            tail->next=new ListNode(v[i]);
            tail=tail->next;
        }
        return ans;
    }
};
