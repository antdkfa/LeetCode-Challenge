/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* now, TreeNode* p, TreeNode* q) {
        if(p->val < now->val && q->val < now->val) return dfs(now->left, p, q);
        else if(p->val > now->val && q->val > now->val) return dfs(now->right, p, q);
        else return now;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};
