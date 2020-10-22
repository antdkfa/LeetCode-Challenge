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
    int ans = 1e9;
    void dfs(TreeNode* now, int depth){
        if(now->left == NULL && now->right == NULL) { ans = min(ans, depth); return;}
        if(now->left) {
            dfs(now->left, depth+1);
        }
        if(now->right) {
            dfs(now->right, depth+1);   
        }   
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, 1);
        return ans;
    }
};
