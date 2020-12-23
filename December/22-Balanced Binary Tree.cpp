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
    bool ans = true;
    int dfs(TreeNode* now){
        if(!now->left && !now->right) return 1;
        int l = 0, r = 0;
        if(now->left) {
            l = dfs(now->left);
        }
        if(now->right) {
            r = dfs(now->right);
        }
        if(abs(l - r) > 1) ans = false;
        return max(l,r) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        dfs(root);
        return ans;
    }
};
