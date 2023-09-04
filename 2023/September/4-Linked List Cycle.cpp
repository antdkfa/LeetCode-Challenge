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
    bool ans;
    map<ListNode*, bool> visited;

    void rec(ListNode* now) {
        if(now == nullptr) return;
        if(visited[now]) {
            ans = true;
            return;
        }
        visited[now] = true;
        rec(now->next);
    }

    bool hasCycle(ListNode *head) {
        rec(head);
        return ans;
    }
};
