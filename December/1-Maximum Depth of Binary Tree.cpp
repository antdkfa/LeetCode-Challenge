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
    int ans;
    void go(TreeNode* now, int depth){
        ans = max(ans, depth);
        if(now->left) {
            go(now->left, depth+1);
        }
        if(now->right){
            go(now->right, depth+1);
        }
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        go(root, 1);
        return ans;
    }
};
