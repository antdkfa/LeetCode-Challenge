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
    int mx[10005], lvl, visited[10005];

    void dfs(int depth, TreeNode* now) {
        if(now == nullptr) return;
        lvl = max(depth, lvl);
        if(!visited[depth]) {
            visited[depth] = 1;
            mx[depth] = now->val;
        } else {
            mx[depth] = max(mx[depth], now->val);
        }
        dfs(depth+1, now->left);
        dfs(depth+1, now->right);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(0,root);

        vector<int> ans;
        if(root == nullptr) return ans;
        ans.resize(lvl+1);
        for(int i=0;i<=lvl;i++) {
            ans[i] = mx[i];
        }

        return ans;
    }
};
