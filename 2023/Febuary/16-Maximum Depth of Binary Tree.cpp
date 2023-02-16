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
    int ans = 0;

    void dfs(TreeNode* now, int depth) {
        if(now) {ans = max(ans, depth);
        dfs(now->left, depth+1);
        dfs(now->right, depth+1);}
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};
