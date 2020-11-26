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
    map<TreeNode*, int> dp;
    
    int go(TreeNode* now) {
        int &ret = dp[now];
        if(dp[now]) return ret;
        int l1 = 0, l2 = 0, l3 = 0, r1 = 0, r2 = 0, r3 = 0;
        if(now->left){
            l1 = go(now->left);
            if(now->left->left) {
                l2 = go(now->left->left);
            }
            if(now->left->right){
                l3 = go(now->left->right);
            }
        }
        
        if(now->right) {
            r1 = go(now->right);
            if(now->right->right) {
                r2 = go(now->right->right);
            } 
            if(now->right->left){
                r3 = go(now->right->left);
            }
        }
        ret = max(l1 + r1, l2 + r2 + l3 + r3 + now->val);
        return ret = dp[now];
    }
    
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        return go(root);
    }
};
