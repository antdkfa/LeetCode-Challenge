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
    typedef pair<int,int> p;
    int ans;
    p dfs(TreeNode* now) {
        if(now == nullptr) return {0,0};
        p left = dfs(now->left);
        p right = dfs(now->right);
        int sub = left.first + right.first + now->val;
        int cnt = left.second + right.second + 1;
        if(sub/cnt == now->val) ans++;
        return {sub, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
