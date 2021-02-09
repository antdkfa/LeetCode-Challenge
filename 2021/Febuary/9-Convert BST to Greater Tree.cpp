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
    int ret=0;
    void dfs(TreeNode* now){
        if(now->right)dfs(now->right);
        ret+=now->val;
        now->val=ret;
        if(now->left)dfs(now->left);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        dfs(root);
        return root;
    }
};
