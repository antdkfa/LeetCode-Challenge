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
    void go(TreeNode *now) {
        if(!now->left && !now->right) return;
        TreeNode *l,*r;
        if(now->left) l = now->left, go(now->left);
        if(now->right) r = now->right, go(now->right);
        now->left = r, now->right = l;
    
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        go(root);
        return(root);
    }
};
