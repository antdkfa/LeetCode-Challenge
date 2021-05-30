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
    vector<int> v;
    void dfs(TreeNode* now) {
        if(now == nullptr) return;
        dfs(now->left);
        v.push_back(now->val);
        dfs(now->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* ans = new TreeNode(v[0]);
        TreeNode* now = ans;
        for(int i = 1;i<v.size();i++){
            TreeNode* tmp = new TreeNode(v[i]);
            now->right = tmp;
            now = now->right;
        }
        return ans;
    }
};
