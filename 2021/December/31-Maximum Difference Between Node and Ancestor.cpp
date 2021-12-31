/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<int,int>p;
    int ans = -1;
    p go(TreeNode *now){
        if(now->left == NULL && now->right == NULL) return {now->val, now->val};
        else if(now->left == NULL && now->right != NULL) {
            p a = go(now->right);
            ans = max(ans, abs(now->val - a.first));
            ans = max(ans, abs(a.second - now->val));
            return { min(a.first, now->val), max(a.second, now->val) };
        }
        else if(now->left != NULL && now->right == NULL){
            p a = go(now->left);
            ans = max(ans, abs(now->val - a.first));
            ans = max(ans, abs(a.second - now->val));
            return { min(a.first, now->val), max(a.second, now->val) };
        }
        else{
            p a = go(now->left);
            p b = go(now->right);
            int mn = min(a.first, b.first), mx = max(a.second, b.second);
            ans = max(ans, abs(now->val - mn));
            ans = max(ans, abs(mx - now->val));
            return { min(mn, now->val), max(mx, now->val) };
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        go(root);
        return ans;
    }
};
