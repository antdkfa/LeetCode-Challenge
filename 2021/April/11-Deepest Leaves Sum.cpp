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
    int ans = 0, mxdepth = -1;
    
    void go(TreeNode* now, int depth) {
        if(depth == mxdepth) ans+= now->val;
        else if(depth > mxdepth) {
            mxdepth = depth;
            ans = now->val;
        }
        if(now->left) go(now->left, depth+1);
        if(now->right) go(now->right, depth+1);
    }
     
    int deepestLeavesSum(TreeNode* root) {
        go(root, 0);
        return ans;
    }
};
