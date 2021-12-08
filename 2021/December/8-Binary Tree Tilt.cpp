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
    int go(TreeNode *now) {
        if(!now) return 0;    
        int left = go(now->left);
        int right = go(now->right);
        int sum = left + right + now->val; 
        now->val = abs(right - left);
        return sum;
    }
    
    int getSum(TreeNode* now) {
        if(!now) return 0;
        int left = go(now->left);
        int right = go(now->right);
        return left + right + now->val;
    }
    
    int findTilt(TreeNode* root) {
        go(root);
        return getSum(root);
    }
};
