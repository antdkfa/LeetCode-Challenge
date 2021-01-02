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
    TreeNode* ans;
    void dfs(TreeNode* now, TreeNode* target){
        if(now->val == target->val) {
            ans = now;
            return;
        }
        if(now->left) dfs(now->left, target);
        if(now->right) dfs(now->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return ans;
    }
};
