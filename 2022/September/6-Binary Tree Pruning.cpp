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
    int dfs(TreeNode* now) {
        if(!now) return 0;
        int left = dfs(now->left);
        int right = dfs(now->right);
        if(!left)now->left=NULL;
        if(!right)now->right=NULL;
        int hasOne = max(now->val, max(left, right));
        if(!hasOne) now=NULL;
        return hasOne;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int result = dfs(root);
        if(!result) root=NULL;
        return root;
    }
};
